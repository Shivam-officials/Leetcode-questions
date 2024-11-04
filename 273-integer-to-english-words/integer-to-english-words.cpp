class Solution
{
    public:
        string numberToWords(int num)
        {
            if (num == 0) return "Zero";
            string ans;
            int batchIndx = 0;
            while (num > 0)
            {
                if (num % 1000 != 0)
                {
                    string batchAns = processBatch(num % 1000, batchIndx);
                    ans = batchAns + ans;
                }
                num /= 1000;
                batchIndx++;
            }
            ans.erase(ans.find_last_not_of(" ") + 1);
            return ans;
        }

    private:
        string processBatch(int currBatch, int batchIndx)
        {
            const string thousandsAndBeyond[] = { "",
                "Thousand",
                "Million",
                "Billion" };
            const string tens[] = { "",
                "",
                "Twenty",
                "Thirty",
                "Forty",
                "Fifty",
                "Sixty",
                "Seventy",
                "Eighty",
                "Ninety" };
            const string ones[] = { "",
                "One",
                "Two",
                "Three",
                "Four",
                "Five",
                "Six",
                "Seven",
                "Eight",
                "Nine",
                "Ten",
                "Eleven",
                "Twelve",
                "Thirteen",
                "Fourteen",
                "Fifteen",
                "Sixteen",
                "Seventeen",
                "Eighteen",
                "Nineteen" };

            string batchAns;
            if (currBatch >= 100)
            {
                int hunsIndx = currBatch / 100;
                batchAns += ones[hunsIndx] + " Hundred ";
                currBatch %= 100;
            }
            if (currBatch >= 20)
            {
                int tensIndx = currBatch / 10;
                batchAns += tens[tensIndx] + " ";
                currBatch %= 10;
            }
            if (currBatch > 0)
            {
                int onesIndx = currBatch;
                batchAns += ones[onesIndx] + " ";
            }
            batchAns += thousandsAndBeyond[batchIndx] + " ";
            return batchAns;
        }
};