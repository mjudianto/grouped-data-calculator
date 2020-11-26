// Program menghitung mean, median, modus data kelompok.
#include<iostream>
#include <bits/stdc++.h> 
#include<iomanip>
using namespace std; 

// Fungsi menghitung mean. 
float mean(float mid[], int freq[], int n) 
{ 
	float sum = 0, freqSum = 0; 
	for (int i = 0; i < n; i++) { 
		sum += mid[i] * freq[i]; 
		freqSum = freqSum + freq[i]; 
	} 
	return sum / freqSum; 
} 

//fungsi mencari nilai tengah class
float mid(float lower[], float upper[], int freq[], int n){
	float mid_value[10];
	for(int i=0 ; i<n ; i++){
		mid_value[i] = (lower[i] + upper[i]) / 2;
	}

	float Mean = mean(mid_value, freq, n);
	return Mean;
}

float median(float lower[], int freq[], int n, int freqSum, int width){
	float median_class;
	median_class = freqSum / 2;
	int median_class_cf = 0;
	int cf = 0; //cumulative frequency / frekuensi kumulatif
	int counter = 0;

	//mencari kelas median dari cf;
	for (int i=0 ; i<n ; i++){
		median_class_cf += freq[i];
		if (median_class_cf >= median_class){
			break;
		}
		counter++;
	}

	//mencari cf sebelum kelas median
	for (int i=0 ; i<n ; i++){
		cf += freq[i];
		if (cf >= median_class_cf){
			cf -= freq[i];
			break;
		}
	}

	return ((lower[counter] - 0.5) + ((median_class - cf) / freq[counter]) * width);
}

//fungsi menghitung modus
float modus(float lower[], int freq[], int n, int width){
	float kelas_modus;
	kelas_modus = 0;
	int counter = -1;
	float b1, b2;

	//mencari kelas modus (kelas yang memiliki frekuensi terbanyak)
	for (int i=0 ; i<n ; i++){
		if (freq[i] >= kelas_modus){
			kelas_modus = freq[i];
			counter++;
		}
	}

	//b1 = f kelas modus - f kelas sebelumnya
	//b2 = f kelas modus - f kelas sesudahnya
	b1 = freq[counter] - freq[counter - 1];
	b2 = freq[counter] - freq[counter + 1];

	return ((lower[counter] - 0.5) + (b1 / (b1 + b2)) * width);
}

int main() 
{ 
	float lower_limit[] = { 2, 4, 6, 8 }; 
	float upper_limit[] = { 4, 6, 8, 10 }; 
	int freq[] = { 3, 4, 2, 1 };
	int length = 0, freqSum = 0;
	length = sizeof(freq) / sizeof(freq[0]);
	int width = upper_limit[0] - lower_limit[0];

	//menghitung total frekuensi
	for (int i=0 ; i<length ; i++){
		freqSum += freq[i];
	}

	//menampilkan tabel class dan frekuensi
	cout<<"Class"<<setw(16)<<"Frequency"<<endl;
	for (int i=0 ; i<length ; i++){
		cout<<lower_limit[i]<<" - "<<upper_limit[i]<<"		"<<freq[i];
		cout<<endl;
	}

	//menghitung mean
	float mean = mid(lower_limit, upper_limit, freq, length);
	cout<<"\nMean : "<<mean<<endl;
	float Median = median(lower_limit, freq, length, freqSum, width);
	cout<<"Median : "<<Median<<endl;
	float Modus = modus(lower_limit, freq, length, width);
	cout<<"Modus : "<<Modus;

	cout<<endl<<endl;
	system("pause");
}