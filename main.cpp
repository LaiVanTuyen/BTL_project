#include <bits/stdc++.h>
#include "fstream"
using namespace std;
string Add(string a, string b);
string Mul(string a, string b);
string Sub(string s1, string s2);
int main() {
    clock_t start, end;   // Khai báo biến thời gian
    double time_use;      // Thời gian sử dụng
    start = clock();     // Lấy thời gian trước khi thực hiện thuật toán
    int test;
    ifstream file("bignumber.in");
    file>>test;
    ofstream file1("bignumber.out");
    while (test--){
        string a,b,c;
        file>>a>>b>>c;
        if (b == "+"){
            file1 << Add(a,c)<<endl;
        }
        if (b=="*"){
            file1<<Mul(a,c)<<endl;
        }
        if (b=="-"){
            file1<<Sub(a,c)<<endl;
        }

    }

    file.close();
    end = clock();  // lấy thời gian sau khi thực hiện
    time_use = (double)(end - start) / CLOCKS_PER_SEC;    //Tính thời gian sử dụng
    cout<<"Thoi gian chay : "<<time_use;

    return 0;
}
string Add(string a, string b){
    string s="";
    int nho =0;
    while (a.size()<b.size()) a = "0"+a;
    while (a.size()>b.size()) b = "0"+b;
    int len = a.size()-1;
    for (int i = len; i >=0 ; i--) {
        int so = int(a[i]-'0') + int(b[i]-'0')+nho;
        s += char(so%10+'0');
        nho=so/10;
    }
    if (nho>0) s += char(nho+'0');
    reverse(s.begin(),s.end());
    return s;
}
string Mul(string s1, string s2){
    int len1=s1.size();
    int len2=s2.size();
    int len = len1+len2;
    vector<int >a,b;
    //gán sâu s1 vào vector a
    for (int i = 0; i < len1; i++) a.push_back(int(s1[i] - '0'));
    for (int i = 0; i < len2; i++) b.push_back(int(s2[i] - '0'));
    vector<vector<int>> res(len2);
    int index =0;
    for (int i = len2-1; i >=0 ; i--) {
        int nho =0,so = 0;
        //thêm số không vào mỗi hàng thụt vào
        int t=0;
        while (t<index){
            res[index].push_back(0);
            t++;
        }
        for (int j = len1-1; j >=0 ; j--) {
            so = a[j]*b[i] + nho;
            res[index].push_back(so%10);
            nho = so/10;
        }
        if (nho>0) res[index].push_back(nho);
        while (res[index].size()<len) res[index].push_back(0);
        reverse(res[index].begin(),res[index].end());
        index++;
    }
    int nho =0;
    string s ="";
    for (int j = res[0].size()-1; j >=0 ; j--) {
        int so =nho;
        for (int i = 0; i < res.size(); i++) so += res[i][j];
        s=char (so%10+'0')+s;
        nho= so/10;
    }
    if (nho>0) s= char(nho+'0')+s;
    while (s[0]=='0') s.erase(s.begin());
    return s;
}
string Sub(string a, string b){
    string s="";
    int nho =0;
    while (a.size()<b.size()) a = "0"+a;
    while (a.size()>b.size()) b = "0"+b;
    bool check = false;
    if (a<b){
        a.swap(b);
        check = true;
    }
    int len = a.size()-1;
    for (int i = len; i >=0 ; i--) {
        int so = int(a[i]-'0') - int(b[i]-'0') - nho;
        if (so < 0) {
            s += char(so + 10 + '0');
            nho = 1;
        }
        else {
            s += char(so + '0');
            nho=0;
        }
    }
    reverse(s.begin(),s.end());
    while (s[0]=='0') s.erase(s.begin());//xóa chữ số 0 thừa
    if (check) s += "-";
    return s;
}