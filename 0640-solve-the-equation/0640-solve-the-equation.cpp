class Solution {
public:
pair<int,int> fun(string str,int start_indx,int end_indx){
   int vlaue=0;
   int variabel=0;
     int sz=str.size();
        int sgin=1;
        for(int i=start_indx;i<end_indx;i++){
            if(str[i] == '=')break;
            else if(str[i] == 'x'){
                variabel+=sgin;
                sgin=1;continue;}

            if(str[i] == '+'){
                sgin=1;
            }
            else if(str[i] == '-'){
                sgin=-1;
            }
            else {
            string num="";
            bool x=0;
            while(i<sz and (str[i]>='0' and str[i]<='9') || str[i]=='x'){
                if(str[i] == 'x')
                    x=1;
                else
                    num+=str[i];
                
                i++;
            }
            i--;
            if(x)
                variabel+=stoi(num)*sgin;
            else 
                vlaue+=stoi(num)*sgin;
            }
        }
        return {vlaue,variabel};
}
    string solveEquation(string e) {
 
        int indx=0,sz=e.size();
        for(int i=0;i<sz;i++){
            if(e[i]=='='){
                indx=i;
                break;
            }
        }       
        auto v_left=fun(e,0,indx);

        auto v_right=fun(e,indx+1,sz);

        if(v_left.second == v_right.second){
            if((v_left.first != 0 || v_right.first !=0) and (v_left.first !=v_right.first)){
                return "No solution";
            }
            else{

                return "Infinite solutions";
            }
        }
        if(v_left.second > v_right.second){
            
            int d=((v_left.second - v_right.second) == 0) ?1:(v_left.second - v_right.second);

            return "x="+to_string((v_right.first-v_left.first)/d);
        }
        
        int d=(( v_right.second-v_left.second ) == 0)?1:( v_right.second-v_left.second );
        
        return "x="+to_string((v_left.first-v_right.first)/d);

    }
};