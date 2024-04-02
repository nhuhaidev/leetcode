#include<iostream>
using namespace std;
int TinhTong(int n,int sum=0) {
	if (n == 0)return sum;
	return TinhTong(n - 1, sum += n);
}
int TinhTongBinhPhuong(int n,int sumBP = 0) {
	if (n == 0) return sumBP;
	return TinhTongBinhPhuong(n - 1, sumBP += n*n);
}
int TinhGiaiThua(int n, int sumGT =1) {
	if (n == 1) return sumGT;
	return TinhGiaiThua(n - 1, sumGT *= n);
}
int TongGiaiThua(int n, int sum = 0) {
	if (n == 0) return sum;
	return TongGiaiThua(n - 1, sum += TinhGiaiThua(n));
}
int TinhCanBac(int n, int x, int sum = 1) {
	if (n == 0) return sum;
	return TinhCanBac(n - 1, x, sum *= x);
}
int DemSo(int n, int SL=0) {
	if (n <= 0) return SL;
	return DemSo(n / 10, SL+=1);
}
int SoDaoNguoc(int n, int sdn =0) {
	if (n <= 0)return sdn;
	return SoDaoNguoc(n / 10, sdn = sdn * 10 + n % 10);
}
int TongChanTongLe
int main() {
	/*cout << TinhTong(3) << endl;
	cout << TinhTongBinhPhuong(3) << endl;
	cout << TinhGiaiThua(3);*/
	cout <<SoDaoNguoc(12345)<<endl;
	system("pause");
	return 1;
}