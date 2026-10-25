#pragma once //헤더가드
#include<iostream>
#include <cstdlib>
namespace jangseoyeon2649035
{
    class book
    {
    //private: 안써도 프라이빗함
        int id;   //id: 1~1000
        int price;   //price: 0~50000 won
        void testID()
        {
            if((id<1) || (id>1000))
            {
                std::cout << "Illegal id value!\n";
                std::exit(1);
            }
        }
        void testPrice()
        {
            if((price<0) || (price>50000))
            {
                std::cout << "Illegal price value!\n";
                std::exit(1);
            }
        }
    public:
        book(int d=1, int p=0):id{d},price{p}
        {
            testID(); testPrice();
        }
        void input()
        {
          std::cout << "Enter book id as a number: ";
           std::cin >> id; testID();
         std::cout << "Enter book price as a number: ";
            std::cin >> price; testPrice();
        }
        void setID(int d){id=d; testID();}
        void setPrice(int p){price=p; testPrice();}
        void print() const
        {
            std::cout << id <<"/" << price << std::endl;
        }
        int getID() const {return id;}
        int getPrice() const {return price;}
        book operator++(){return book{id, ++price};}//price만 증가
        book operator++(int)
        {
            book temp{id, price};
            price++;
            return temp;
            //return book{id, price++};
        }
        //book b; b++; ++b;
        friend std::istream& operator >> (std::istream& is, book& b)
        {
            //book; std::cout <<"Enter book id price";std::cin>>b
            is>>b.id>>b.price;b.testID(); b.testPrice();
            //book b; std::cin >>b;
            std::cout << "Enter book id as a number: ";
            std::cin >> b.id; b.testID();
            std::cout << "Enter book price as a number: ";
            std::cin >> b.price; b.testPrice();
            return is;
        }
        friend std::ostream& operator<< (std::ostream& os, const book& b)
        {
            os << b.id <<", "<<b.price <<"won\n";
            return os;
        }
        friend bool operator==(const book&b1, const book& b2)
        {
            return b1.id ==b2.id && b1.price ==b2.price;
        }
        friend int operator+(const book&b1, const book& b2)
        {
            return b1.price +b2.price;
        }
    };
}
// 1. 본인이름학번의 네임스페이스
// -본인이름학번 네임스페이스 예: 이름이 김프로이고 학번이 1234567일 경우 KimPro1234567
// using 지시자는 cpp파일에서는 영역 { block } 안에서 사용, 헤더파일엔 using 지시자는 사용하지 않고 네임스페이스 지정자를 사용합니다.
// -using 지시자 예: { using namespace std; cout << "Enter your id: "; }
// -네임스페이스 지정자 예: std::cout << "Enter your id: ";


// 2. 클래스명.h: 클래스 정의
// 1의 본인이름학번의 네임스페이스 안에 클래스를 정의하고 멤버함수들도 모두 인라인으로 구현합니다. 
// private 멤버변수 선언 (2개 이상)
// private 멤버함수 정의
// -test멤버변수1: 멤버변수1 범위가 아니면 프로그램 종료
// -test멤버변수2: 멤버변수2 범위가 아니면 프로그램 종료
// public 멤버함수 정의
// -input: 표준스트림입력으로 멤버변수들 입력, test함수들 호출
// -set 접근함수들: 멤버변수 값 설정 및 test함수 호출
// -print: 표준스트림출력으로 멤버변수들 출력
// -get 접근함수들: 멤버변수 값 리턴