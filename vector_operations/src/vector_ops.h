#pragma once
#include <vector>
#include <iostream>

namespace task {
	std::vector<double> operator+(const std::vector<double>& a,
            const std::vector<double>& b) {
            std::vector<double> res(a.size());
            for (auto i = 0; i < a.size(); i++) {
                res[i] = a[i] + b[i];
            }
            return res;
	}

	std::vector<double> operator+(const std::vector<double>& a) {
            return a;
	}

	std::vector<double> operator-(const std::vector<double>& a,
            const std::vector<double>& b) {
            std::vector<double> res(a.size());
            for (auto i = 0; i < a.size(); i++) {
	        res[i] = a[i] - b[i];
            }
            return res;
	}

	std::vector<double> operator-(const std::vector<double>& a) {
            std::vector<double> res(a.size());
            for (auto i = 0; i < a.size(); i++) {
	        res[i] = -a[i];
            }
            return res;
	}

	double operator*(const std::vector<double>& a,
            const std::vector<double>& b) {
            double res = 0;
            for (auto i = 0; i < a.size(); i++) {
	        res += a[i] * b[i];
            }
            return res;
	}

	std::vector<double> operator%(const std::vector<double>& a,
	    const std::vector<double>& b) {
            std::vector<double> res(3);
            res[0] = a[1] * b[2] - a[2] * b[1];
            res[1] = a[2] * b[0] - a[0] * b[2];
            res[2] = a[0] * b[1] - a[1] * b[0];
            return res;
	}

	double norm(const std::vector<double>& a) {
            double norm = 0;
            for (auto i = 0; i < a.size(); i++) {
	        norm += a[i] * a[i];
            }
            return sqrt(norm);
	}

	bool operator||(const std::vector<double>& a,
	    const std::vector<double>& b) {
            const double EPS = 1e-7;
            return norm(a) * norm(b) - abs(a * b) < EPS;
	}

	bool operator&&(const std::vector<double>& a,
	    const std::vector<double>& b) {
	    if (norm(a) == 0 || norm(b) == 0) { 
	        return 1; 
	    }
            return (a || b) && (a * b > 0);
	}

	std::istream& operator>>(std::istream& in, std::vector<double>& vec) {
            size_t s;
            in >> s;
            
            vec.resize(s);
            for (auto i = 0; i < s; i++) {
	        in >> vec[i];
            }
            return in;
	}

	std::ostream& operator<<(std::ostream& out, std::vector<double>& v) {
            for (auto el : v) {
                out << el << ' ';
            }
            out << '\n';
            return out;
	}

	void reverse(std::vector<double>& v) {
	    for (size_t i = 0; i != v.size() / 2; i++) {
	        std::swap(v[i], v[v.size() - 1 - i]);
            }
	}

	std::vector<int> operator&(const std::vector<int>& a,
	    const std::vector<int>& b) {
            std::vector<int> res(a.size());
            for (size_t i = 0; i < a.size(); i++) {
	        res[i] = a[i] & b[i];
            }
            return res;
	}

	std::vector<int> operator|(const std::vector<int>& a,
	    const std::vector<int>& b) {
            std::vector<int> res(a.size());
            for (size_t i = 0; i < a.size(); i++) {
                res[i] = a[i] | b[i];
            }
            return res;
	}
}
