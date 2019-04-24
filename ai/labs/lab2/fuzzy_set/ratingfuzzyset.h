#ifndef RATINGFUZZYSET_H
#define RATINGFUZZYSET_H
#include <map>
using std::map;

#include <array>
using std::array;

#define ELEMENTS 6
enum eAdvantages// : unsigned
{
    APSEND = 1,
    INTERMEDIATE_WEAK = 2,
    WEAK = 3,
    INTERMEDIATE_ESSENTIAL = 4,
    ESSENTIAL = 5,
    INTERMEDIATE_APPARENT = 6,
    APPARENT = 7,
    INTERMEDIATE_ABSOLUTE = 8,
    ABSOLUTE = 9
};

enum eRating// : unsigned
{
    LOW = 50,
    LIGHT_MIDDLE = 60,
    MIDDLE = 70,
    LIGHT_HIGH = 80,
    HIGH = 90,
    MAXIMAL = 100
};

class RatingFuzzySet
{
    map<eRating, eAdvantages> mapValues;
    array<array<float, ELEMENTS>, ELEMENTS> arMatrixFS;
public:
    RatingFuzzySet();

    map<eRating, eAdvantages> getMapValues() const;

    array<array<float, ELEMENTS>, ELEMENTS> calculateMtxVls();

    array<int, ELEMENTS>&& toArray() const;

    array<float, ELEMENTS>&& calculateColSum();

    map<eRating, float> calculateBlngValues();
};

#endif // RATINGFUZZYSET_H
