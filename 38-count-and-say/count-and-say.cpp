class Solution {
public:
    string countAndSay(int n) {
        /*
            count && say sequence
            i->1
            i+1-> ekk bar lekha hai hai above mai=>1,1
            i+2-> 2 baar 2 lekha hai above =>2,1
            i+3=>essay upper ekk bar 2 lekha hai ekk bar 2 lekah hai =>1211

            simple yay meaning hai uss no kay ketnay baar kaya lekha hai ussay ham number mai lekha rahay hai  
            jaisay 21= ekk bar 2 lekha hai or 1 bar one lekaha hai
            ekk bar=1
            do lekha hai =2
            ekk bar =1
            one lekha hai 1
            ans=1211
        */

        if(n==1)
        {
            return "1";
        }
        string say=countAndSay(n-1);
        //processing
        string result="";
        for(int i=0;i<say.length();i++)
        {
            char ch=say[i];
            int count=1;

            while(i<say.length()-1 && say[i]==say[i+1])
            {
                count++;
                i++;
            }

            result+=to_string(count)+string(1,ch);
        }

        return result;


    }
};