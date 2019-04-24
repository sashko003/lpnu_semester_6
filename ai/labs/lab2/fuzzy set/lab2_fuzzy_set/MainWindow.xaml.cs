using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using lab2_fuzzy_set;

namespace lab2_fuzzy_set
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private RatingFuzzySet fs;

        public MainWindow()
        {
            InitializeComponent();
            fs = new RatingFuzzySet();
            fs.setRatingSet();
            //List<List<float>> liMatrix = fs.buildMatrix();
            fillMatrix(fs);
            fs.calculateBelongValues();
        }

        public void fillMatrix(RatingFuzzySet fs)
        { 
            List<List<float>> liMatrix = fs.buildMatrix();
            List<TempRow> liRows = new List<TempRow>();
            foreach(var row in liMatrix)
            {
                var obj = new { val1 = row[0], val2 = row[1], val3 = row[2], val4 = row[3], val5 = row[4], val6 = row[5] };
                liRows.Add(new TempRow() {_50 = row[0], _60 = row[1], _70 = row[2], _80=row[3], _90=row[4], _100 = row[5]});
                //this.Matrix.ItemsSource = row;
            }
            List<String> liHeader = new List<String>(){"Ratings", "50", "60", "70", "80", "90", "100"};
            this.Matrix.ItemsSource = liHeader;
            this.Matrix.ItemsSource = liRows;
            DataTable table = new DataTable() {Columns = { "Ratings", "50", "60", "70", "80", "90", "100" } };
            this.Matrix.DataContext = table;
        }
    }
}
