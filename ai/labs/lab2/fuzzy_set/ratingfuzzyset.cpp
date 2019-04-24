#include "ratingfuzzyset.h"

RatingFuzzySet::RatingFuzzySet()
{ 
    mapValues.insert(std::make_pair(LOW, APSEND));
    mapValues.insert(std::make_pair(LIGHT_MIDDLE, WEAK));
    mapValues.insert(std::make_pair(MIDDLE, ESSENTIAL));
    mapValues.insert(std::make_pair(LIGHT_HIGH, APPARENT));
    mapValues.insert(std::make_pair(HIGH, INTERMEDIATE_ABSOLUTE));
    mapValues.insert(std::make_pair(MAXIMAL, ABSOLUTE));
}

map<eRating, eAdvantages> RatingFuzzySet::getMapValues() const
{
    return this->mapValues;
}

array<array<float, ELEMENTS>, ELEMENTS> RatingFuzzySet::calculateMtxVls()
{
    array<array<float, ELEMENTS>, ELEMENTS> arMtx;
    array<int, ELEMENTS> arRatings(toArray());
    for(int i = 0; i<ELEMENTS; ++i){
        for(int j = 0; j<ELEMENTS; ++j){
            int iAssesR = mapValues.at((eRating)arRatings[i]);
            int iAssesC = mapValues.at((eRating)arRatings[j]);
            arMtx[i][j] = (float)iAssesR/(float)iAssesC;
        }
    }
    this->arMatrixFS = std::move(arMtx);
    return this->arMatrixFS;
}

array<int, ELEMENTS>&& RatingFuzzySet::toArray() const
{
    array<int, ELEMENTS> arrRating;
    arrRating[0] = LOW;
    arrRating[1] = LIGHT_MIDDLE;
    arrRating[2] = MIDDLE;
    arrRating[3] = LIGHT_HIGH;
    arrRating[4] = HIGH;
    arrRating[5] = MAXIMAL;
    return std::move(arrRating);
}

array<float, ELEMENTS>&& RatingFuzzySet::calculateColSum()
{
    array<float, ELEMENTS> arrSums;
    for(int i = 0; i<ELEMENTS; ++i){
        for(int j = 0; j<ELEMENTS; ++j){
            arrSums[i] += this->arMatrixFS[j][i];
        }
    }
    return std::move(arrSums);
}

map<eRating, float> RatingFuzzySet::calculateBlngValues()
{
    map<eRating, float> mapBlngVals;
    array<float, ELEMENTS> arrSums(calculateColSum());
    map<eRating, eAdvantages>::iterator itMap = this->mapValues.begin();
    for(int i = 0; i<ELEMENTS; ++i){
        mapBlngVals.insert(std::make_pair(itMap->first, (1.0/arrSums[i]) ));
        ++itMap;
    }
    return mapBlngVals;
}
