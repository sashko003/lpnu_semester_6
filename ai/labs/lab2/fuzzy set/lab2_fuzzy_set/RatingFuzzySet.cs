using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab2_fuzzy_set
{
    class RatingFuzzySet
    {
        protected Dictionary<eRating, eAdvantages> fzRating;
        protected ArrayList vBelongValues;
        
        protected List<eRating> createRatingList()
        {
            List<eRating> liRatings = new List<eRating>();
            liRatings.Add(eRating.LOW);
            liRatings.Add(eRating.LIGHT_MIDDLE);
            liRatings.Add(eRating.MIDDLE);
            liRatings.Add(eRating.LIGHT_HIGH);
            liRatings.Add(eRating.HIGH);
            liRatings.Add(eRating.MAXIMAL);
            return liRatings;
        }
        public void setRatingSet()
        {
            vBelongValues = new ArrayList();
            fzRating = new Dictionary<eRating, eAdvantages>();
            fzRating.Add(eRating.LOW, eAdvantages.ABSOLUTE);
            fzRating.Add(eRating.LIGHT_MIDDLE, eAdvantages.INTERMEDIATE_ABSOLUTE);
            fzRating.Add(eRating.MIDDLE, eAdvantages.APPARENT);
            fzRating.Add(eRating.LIGHT_HIGH, eAdvantages.ESSENTIAL);
            fzRating.Add(eRating.HIGH, eAdvantages.WEAK);
            fzRating.Add(eRating.MAXIMAL, eAdvantages.APSEND);
        }

        public List<List<float>> buildMatrix()
        {
            List<List<float>> liMatrix = new List<List<float>>(fzRating.Count);
            List<eRating> liRatings = this.createRatingList();
            for(int i = 0; i < fzRating.Count; ++i)
            {
                for (int j = 0; j<fzRating.Count; ++j)
                {

                    liMatrix[i][j] = new float(); // = fzRating[liRatings[i]]/fzRating[liRatings[j]];
                }
            }
            return liMatrix;
        }

        protected float calculateColumnSum()
        {
            float fSum = new float();

            return fSum;
        }
        ArrayList calculateBelongValues()
        {
             
            return vBelongValues;
        }
        public void displayGraph()
        {

        }
             
    }

    enum eAdvantages
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
    }

    enum eRating 
    {
        LOW = 50,
        LIGHT_MIDDLE = 60,
        MIDDLE = 70,
        LIGHT_HIGH = 80,
        HIGH = 90,
        MAXIMAL = 100
    }
}


