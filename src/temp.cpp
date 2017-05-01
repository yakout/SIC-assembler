//#include <bits/stdc++.h>
//typedef int integer;
//#define int long long
//#define pb push_back
//#define mp make_pair
//#define mod 1000000007
//#define sz(x) (int) (x).size()
//using namespace std;
//
//int BLANK_1_POS = 8;
//int BLANK_2_POS = 15;
//int BLANK_3_POS = 16;
//int LABEL_START_POS = 0;
//int LABEL_LEN = 8;
//int OPCODE_START_POS = 9;
//int OPCODE_LEN = 6;
//int OPERAND_START_POS = 17;
//int OPERAND_LEN = 18;
//
//string extractWord(string s){
//    int end = s.length() - 1;
//    while (end >= 0 && s[end] == ' '){
//        end--;
//    }
//    if (end == -1){
//        return NULL;
//    }
//    for (int i = 0; i <= end; i++){
//        if (!isalpha(s[i])){
//            return NULL;
//        }
//    }
//    return s.substr(0, end + 1);
//}
//
//void parseInstruction(string s){
//    if (s[0] == '.'){
//        // comment
//        return;
//    }
//    if (s[BLANK_1_POS] != ' '){
//        // error
//        return;
//    }
//    string label = extractWord(s.substr(LABEL_START_POS, LABEL_LEN));
//    string opCode = extractWord(s.substr(OPCODE_START_POS, OPCODE_LEN));
//    if ((s.length() > BLANK_2_POS && s[BLANK_2_POS] != ' ') || (s.length() > BLANK_3_POS && s[BLANK_3_POS] != ' ')){
//        // error
//        return;
//    }
//    string operand = NULL;
//    if (s.length() > OPERAND_START_POS){
//        operand = extractWord(s.substr(OPERAND_START_POS, OPERAND_LEN));
//    }
//
//}
//
//integer main() {
//    ios_base::sync_with_stdio(false);
//
//    string s;
//    regex instruction(".{8}\\s.{2}");
////    getline(cin , s);
//    if (regex_match("           ", instruction)){
//        cout << 'a';
//    }
//
//}
