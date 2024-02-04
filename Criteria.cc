#include "Criteria.h"

ostream& operator<<(ostream& ost, Criteria& c){
    c.print(ost);
    return ost;
}

void A_Criteria::print(ostream& ost) const{
    ost << "Will match song by Artist: " << this->artist;
}

bool A_Criteria::matches(const Song& s) const{
    return (s.getArtist() == this->artist);
}

void C_Criteria::print(ostream& ost) const{
    ost << " Will match song by Category: " << this->category;
}

bool C_Criteria::matches(const Song& s) const{
    return (s.getCategory() == this->category);
}

void AorC_Criteria::print(ostream& ost) const{
    A_Criteria::print(ost);
    C_Criteria::print(ost);
}

bool AorC_Criteria::matches(const Song& s) const{
    return (C_Criteria::matches(s) || A_Criteria::matches(s));
}