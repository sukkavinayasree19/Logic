//1 2 4 8 -hours.
//1 2 4 8 16 32 -minutes (ON LED)
//logic
int bitcount(int bits)
{
    int count=0;
    for(;bits;bits&=bits-1)  //logical AND for checking the count of leds.minutes=>count on led's.
    {
       count++; 
    }
    return count;
}//logic.
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
       vector<string> result;
        //check all possibilities so that hrs+min=num;
        for(int h=0;h<12;++h)
        {
            for(int m=0;m<60;++m)
            {
                if(bitcount(h)+bitcount(m)==num)
                {
                    string hour=to_string(h);
                    string min=(m>=10)?to_string(m):"0"+to_string(m);
                    result.emplace_back(hour+":"+min);
                }
            }
        }
        
        return result;
    }
};
