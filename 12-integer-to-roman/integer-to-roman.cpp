class Solution
{
    public:
        string intToRoman(int num)
        {
            string ths[4] = { "",
                "M",
                "MM",
                "MMM" };
            string hens[11] = { "",
                "C",
                "CC",
                "CCC",
                "CD",
                "D",
                "DC",
                "DCC",
                "DCCC",
                "CM",
                "M" };
            string tens[11] = { "",
                "X",
                "XX",
                "XXX",
                "XL",
                "L",
                "LX",
                "LXX",
                "LXXX",
                "XC",
                "C" };
            string ones[11] = { "",
                "I",
                "II",
                "III",
                "IV",
                "V",
                "VI",
                "VII",
                "VIII",
                "IX",
                "X" };
            return ths[num / 1000] + hens[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
        }
};