#pragma once
#include <vector>
#include <iostream>


namespace task {

	using namespace std;

	vector<double> operator +(const vector<double>& a,
		const vector<double>& b) {

		vector<double> res(a.size());
		for (auto i = 0; i < a.size(); i++) {
			res[i] = a[i] + b[i];
		}
		return res;
	}

	vector<double> operator +(const vector<double>& a) {

		return a;
	}

	vector<double> operator -(const vector<double>& a,
		const vector<double>& b) {

		vector<double> res(a.size());
		for (auto i = 0; i < a.size(); i++) {
			res[i] = a[i] - b[i];
		}
		return res;
	}

	vector<double> operator -(const vector<double>& a) {

		vector<double> res(a.size());
		for (auto i = 0; i < a.size(); i++) {
			res[i] = -a[i];
		}
		return res;
	}

	double operator *(const vector<double>& a,
		const vector<double>& b) {

		double res = 0;
		for (auto i = 0; i < a.size(); i++) {
			res += a[i] * b[i];
		}
		return res;
	}

	vector<double> operator %(const vector<double>& a,
		const vector<double>& b) {

		vector<double> res(3);
		res[0] = a[1] * b[2] - a[2] * b[1];
		res[1] = a[2] * b[0] - a[0] * b[2];
		res[2] = a[0] * b[1] - a[1] * b[0];
		return res;
	}

	double norm(const vector<double>& a) {

		double norm = 0;
		for (auto i = 0; i < a.size(); i++) {
			norm += a[i] * a[i];
		}
		return sqrt(norm);
	}

	bool operator ||(const vector<double>& a,
		const vector<double>& b) {

		const double EPS = 1e-7;
		return norm(a) * norm(b) - abs(a * b) < EPS;
	}

	bool operator &&(const vector<double>& a,
		const vector<double>& b) {

		return (a || b) && (a * b > 0);
	}

	istream& operator >>(istream& in, vector<double>& vec) {

		size_t s;
		in >> s;

		vec.resize(s);
		for (auto i = 0; i < s; i++) {
			in >> vec[i];
		}
		return in;
	}

	ostream& operator <<(ostream& out, vector<double>& v) {

		for (auto el : v) {
			out << el << ' ';
		}
		out << '\n';
		return out;
	}

	void reverse(vector<double>& v) {

		size_t left = 0;
		size_t right = v.size() - 1;
		while (left < right) {
			swap(v[left++], v[right--]);
		}
	}

	vector<int> operator &(const std::vector<int>& a,
		const std::vector<int>& b) {

		vector<int> res(a.size());
		for (size_t i = 0; i < a.size(); i++) {
			res[i] = a[i] & b[i];
		}
		return res;
	}

	vector<int> operator |(const std::vector<int>& a,
		const std::vector<int>& b) {

		vector<int> res(a.size());
		for (size_t i = 0; i < a.size(); i++) {
			res[i] = a[i] | b[i];
		}
		return res;
	}


}  // namespace task
