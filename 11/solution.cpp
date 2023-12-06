string reverseString(string &str){
    if(str == "" || str == " "){
        return "";
    }
    string ans;
    int start = str.length() - 1;
    while(start >= 0){
        if(str[start] == ' '){
            start--;
        }
        else{
            if(ans.length() > 0){
                ans.push_back(' ');
            }
            int j = start;
            while(j >= 0 && str[j] != ' '){
                j--;
            }
            ans.append(str.substr(j+1, start-j));
            start = j;
        }
    }
    return ans;
}