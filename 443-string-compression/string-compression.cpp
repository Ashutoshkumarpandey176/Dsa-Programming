class Solution {
public:
    int compress(vector<char>& chars) {

       int n=chars.size();
       int index=0;
       int i=0;
       while(i<n)
       {
          char curr_char=chars[i];
          int count=0;

         // find the count duplicate element 
          while(i<n && chars[i]==curr_char)
          {
            count++;
            i++;
          }

          //now do the asgin work hear we assgin the charectar
          chars[index]=curr_char;
          index++;
            // we assgin the charectar count 
           if(count>1)
           {
               string count_str=to_string(count);// we convert the string to character

               for(char &ch:count_str) // we use this beacuse of the count is 10 then we have to "1" and "0" that's why we use the loop
               {
                    chars[index]=ch;
                    index++;
               }

           }
       }
       return index;
    }
};