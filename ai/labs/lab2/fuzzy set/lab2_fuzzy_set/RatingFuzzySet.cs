using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab2_fuzzy_set
{
    public class RatingFuzzySet
    {
        protected Dictionary<eRating, eAdvantages> fzRating;
        protected ArrayList vBelongValues;
        protected List<List<float>> liFzMatrix;
        
        public List<eRating> createRatingList()
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
            liFzMatrix = new List<List<float>>();
            List<eRating> liRatings = this.createRatingList();
            liFzMatrix.Add(new List<float>(fzRating.Count));
            for (int i = 0; i < liRatings.Count; ++i)
            {
                liFzMatrix[0].Add((float)fzRating[liRatings[i]]);
            }

            for (int i = 1; i < fzRating.Count; ++i)
            {
                liFzMatrix.Add(new List<float>());
                for (int j = 0; j<fzRating.Count; ++j)
                {
                    float fTempRatingR = (float)fzRating[liRatings[i]];
                    float fTempRatingC = (float)fzRating[liRatings[j]];
                    liFzMatrix[i].Add(fTempRatingR/fTempRatingC);
                }
            }
            return liFzMatrix;
        }

        protected float calculateColumnSum(int iColNum)
        {
            float fSum = new float();
            for(int i = 0; i<liFzMatrix[iColNum].Count; ++i)
            {
                fSum += liFzMatrix[iColNum][i];
            }
            return fSum;
        }
        public ArrayList calculateBelongValues()
        {
            for(int i = 0; i< fzRating.Count; ++i)
            {
                float fColSum = this.calculateColumnSum(i);
                vBelongValues.Add((1 / fColSum) / liFzMatrix[liFzMatrix.Count-1].Max());
            }  
            return vBelongValues;
        }
        public void displayGraph()
        {

        }
             
    }

    public enum eAdvantages
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

    public enum eRating 
    {
        LOW = 50,
        LIGHT_MIDDLE = 60,
        MIDDLE = 70,
        LIGHT_HIGH = 80,
        HIGH = 90,
        MAXIMAL = 100
    }

    public class TempRow
    {
        public float _50 { get; set; }
        public float _60 { get; set; }
        public float _70 { get; set; }
        public float _80 { get; set; }
        public float _90 { get; set; }
        public float _100 { get; set; }

    }
}


