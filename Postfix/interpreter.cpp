//
// Created by naman on 2017-10-22.
//
#include <iostream>
#include "interpreter.h"
#include <iterator>


// executes an operator, returns a string of execution result
// most operators will return the empty string "", except for RQ, PRINT
// If an operator causes a container exception, throw the caught exception

std::string Interpreter::execOp(std::string optr) {
    if (optr == "+") {
        int right = bin.pop();
        int left = bin.pop();
        int answer = right + left;
        tube.enqueue(toString(answer));
        return "";


    } else if (optr == "-") {
        int right = bin.pop();
        int left = bin.pop();
        int answer = left - right;
        tube.enqueue(toString(answer));
        return "";

    } else if (optr == "*") {
        int right = bin.pop();
        int left = bin.pop();
        int answer = left * right;
        tube.enqueue(toString(answer));
        return "";

    } else if (optr == "/") {
        int right = bin.pop();
        int left = bin.pop();
        int answer = left / right;
        tube.enqueue(toString(answer));
        return "";

    } else if (optr == "^") {
        int right = bin.pop();
        int left = bin.pop();
        int answer = recpow(left, right);
        tube.enqueue(toString(answer));
        return "";

    } else if (optr == "RQ") {
        string final;
        int h = bin.size();
        for (int i = 0; i < h; i++) {
            int b = bin.pop();
            tube.enqueue(toString(b));
            sparebin.push(b);
        }

        if (!sparebin.isEmpty()) {
            int c[sparebin.size()];

            int f = sparebin.size();
            for (int i = f - 1; i >= 0; i--) {
                c[i] = sparebin.pop();
            }

            for (int i = f - 1; i >= 0; i--) {
                if (i == 0) {
                    final = final + toString(c[i]);
                    bin.push(c[i]);
                } else {
                    final = final + toString(c[i]) + " ";
                    bin.push(c[i]);
                }
            }

        }


        return final;


    } else if (optr == "PRINT") {

        int o = tube.size();
        string print;
        for (int i = 0; i < o; i++) {
            if (tube.size() == 1) {
                print = print + tube.dequeue();
            } else {
                string p = tube.dequeue();
                print = print + p + " ";
            }
        }
        tube.enqueue("#");
        return print;
    } else if (optr == "#") {
        return 0;
    }

    return "";
}

int Interpreter::recpow(int x, int y) {
        if (y <= 0) {
            return 1;
        }
        if (y == 1) {
            return x;
        }
        int temp = recpow(x, y/2);
        int result = temp*temp;
        if (y % 2 == 0) {
            return result;
        }
        return result*x;
    }


Interpreter::Interpreter() {

}

Interpreter::Interpreter(const Interpreter &itpt) {
    tube = itpt.tube;
    bin  = itpt.bin;
    sparebin=itpt.sparebin;

}

Interpreter &Interpreter::operator=(const Interpreter &itpt) {
    if (this == &itpt) {
        return *this;
    } else {
        this->tube = itpt.tube;
        this->bin = itpt.bin;
        this->sparebin = itpt.sparebin;
        return *this;
    }
}

// Loads a single instruction into the tube
// Requires parsing the instruction into operators and operands
// If tube already contains items, the instruction is loaded
//   without clearing the tube contents
// This should inject a "#" operator at the end


void Interpreter::load(std::string instruction) {

    std::istringstream buffer(instruction);
    std::vector<std::string> ret;

    std::copy(std::istream_iterator<std::string>(buffer), std::istream_iterator<std::string>(),
              std::back_inserter(ret));

    for (int i = 0; i < ret.size(); i++) {

        tube.enqueue(ret[i]);

    }
    tube.enqueue("#");


}

bool Interpreter::hasMoreInstructions() {
    Queue<std::string> copytube;
    copytube.operator=(tube);
    for (int i = 0; i < tube.size(); i++) {
        if (copytube.dequeue() == "#") {
            return true;
        }
    }
    return false;
}

std::string Interpreter::next() {


    int j = tube.size();
    string final1 = "";
    if (j == 1) {
        throw std::out_of_range("Out of range!");
    }
    for (int i = 0; i < j; i++) {
        string a = tube.dequeue();

        if (a == "+") {
            int right = bin.pop();
            int left = bin.pop();
            int answer = right + left;
            tube.enqueue(toString(answer));
            final1 = final1 + "";


        } else if (a == "-") {
            int right = bin.pop();
            int left = bin.pop();
            int answer = left - right;
            tube.enqueue(toString(answer));
            final1 = final1 + "";


        } else if (a == "*") {
            int right = bin.pop();
            int left = bin.pop();
            int answer = left * right;
            tube.enqueue(toString(answer));
            final1 = final1 + "";


        } else if (a == "/") {
            int right = bin.pop();
            int left = bin.pop();
            int answer = left / right;
            tube.enqueue(toString(answer));
            final1 = final1 + "";


        } else if (a == "^") {
            int right = bin.pop();
            int left = bin.pop();
            int answer = recpow(left, right);
            tube.enqueue(toString(answer));
            final1 = final1 + "";


        } else if (a == "RQ") {
            string final;
            int h = bin.size();
            for (int i = 0; i < h; i++) {       //problem in bin
                int b = bin.pop();
                tube.enqueue(toString(b));
                sparebin.push(b);
            }

            if (!sparebin.isEmpty()) {
                int c[sparebin.size()];

                int f = sparebin.size();
                for (int i = f - 1; i >= 0; i--) {
                    c[i] = sparebin.pop();
                }

                for (int i = f - 1; i >= 0; i--) {
                    if (i == 0) {
                        final = final + toString(c[i]);
                        bin.push(c[i]);
                    } else {
                        final = final + toString(c[i]) + " ";
                        bin.push(c[i]);
                    }
                }

            }


            final1 = final1 + final;

        } else if (a == "PRINT") {

            int o = tube.size();
            string print;
            for (int i = 0; i < o; i++) {
                if (tube.size() == 1) {
                    print = print + tube.dequeue();
                } else {
                    string p = tube.dequeue();
                    print = print + p + " ";
                }
            }
            tube.enqueue("#");
            final1 = final1 + print;
        } else if (a == "#") {
            return final1;
        } else {
            int aa = toInt(a);
            bin.push(aa);
        }
    }
    return "";

}

std::string Interpreter::run() {
    Queue<std::string> copytube1;
    int j = tube.size();
    copytube1.operator=(tube);
    int count = 0;
    for (int i = 0; i < j; i++) {
        if ("#" == copytube1.dequeue()) {
            count++;
        }
    }
    for (int j = 1; j < count; j++) {
        next();
    }

    return next();


}

void Interpreter::clear() {
    while (!tube.isEmpty()) {
        tube.dequeue();
    }

    while (!bin.isEmpty()) {
        bin.pop();
    }

    while (!sparebin.isEmpty()) {
        sparebin.pop();
    }


}






