#ifndef CRITERIA_H
#define CRITERIA_H

#include "Song.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Criteria{
    friend ostream& operator<<(ostream&, Criteria&);
    public:
        virtual bool matches(const Song&) const = 0;
        virtual void print(ostream& ost) const = 0;
};

class A_Criteria : virtual public Criteria{
    public:
        A_Criteria(const string& artist) : artist(artist) { }
        virtual bool matches(const Song&) const;
        virtual void print(ostream& ost) const;
        // virtual string getArtist() const;
    private:
        string artist;

};

class C_Criteria : virtual public Criteria{
    public:
        C_Criteria(const string& category) : category(category) { }
        virtual bool matches(const Song&) const;
        virtual void print(ostream& ost) const;
        // virtual string getCategory() const;
    private:
        string category;
};

class AorC_Criteria : public A_Criteria, public C_Criteria{
    public:
        AorC_Criteria(const string& artist, const string& category) : A_Criteria(artist), C_Criteria(category) { }
        virtual bool matches(const Song&) const;
        virtual void print(ostream& ost) const;

};

#endif