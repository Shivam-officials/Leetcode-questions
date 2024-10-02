class Solution {
public:
    string intToRoman(int num) {
         string ans = "";
    // romanMapping.insert( make_pair(1, "I")) ;
    // romanMapping.insert( make_pair(5, "V")) ;
    // romanMapping.insert( make_pair(10, "X")) ;
    // romanMapping.insert( make_pair(50, "L")) ;
    // romanMapping.insert( make_pair(100, "C")) ;
    // romanMapping.insert( make_pair(500, "D")) ;
    // romanMapping.insert( make_pair(1000, "M")) ;

    while(num>0){
        cout << "nums is "<<num <<" current roman is "<<ans<< endl;
        if(num>=1000){
            ans+="M";
            num -= 1000;
        }else if (num>=500) {
            if(to_string(num)[0]=='9' )
            {
                ans += "CM";
                num -= 900;
            }else {
            ans+="D";
            num -= 500;
            }
            
        } else if (num >=100) {

            if (to_string(num)[0]=='4' ) {
                ans += "CD";
                num -= 400;
            }else 
            {
             ans += "C";
             num -= 100;
            }

        
        }else if (num >= 50) {
            if (to_string(num)[0]=='9') {
             ans += "XC";
             num -= 90;
            }else 
            {    
            ans += "L";
            num -= 50;
            }

        }else if (num>=10) {
            if (to_string(num)[0]=='4') {
            ans += "XL";
            num -= 40;
            }else 
            {
            ans += "X";
            num -=10;
            }

        }else if (num >= 5) {
            if (to_string(num)[0]=='9') {
            ans += "IX";
            num -= 9;
            }else 
            {       
            ans += "V";
            num -= 5;
            }
        }else {
            if (to_string(num)[0]=='4') {
            ans += "IV";
            num -= 4;
            }else 
            {        
            ans += "I";
            num -= 1;
            }
        }
    }
    return ans;
    }
};