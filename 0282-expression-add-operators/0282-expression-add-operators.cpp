class Solution{
    public:
        void Finde(int i, string path, long sum, long prev, string num, int target) {
            if (i==num.size()) {
                if (sum==target) result.push_back(path);
                return;
            }
            for (int j = i; j < num.size(); j++) {
                if (j > i && num[i] == '0') break;
                long number = stol(num.substr(i, j - i + 1));
                string temp = num.substr(i, j - i + 1);
                if (i == 0) Finde(j + 1, temp, number, number, num, target);
                else {
                Finde(j+1,path+'+'+temp,sum+number,number,num,target);
                Finde(j+1,path+'-'+temp,sum-number,-number,num,target);
                Finde(j+1,path+'*'+temp,sum-prev+(prev*number),prev*number,num,target);
                }
            }
        }
    vector<string>result;
    vector<string> addOperators(string num, int target) {
        Finde(0,"",0,0,num,target);
        return result;
    }
};