using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Channels;
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

namespace AnagrammeWPF
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        private String[] historique;
        private String[] tabMots;
        static int NBMAX_ESSAIS = 5;
        int nbPartie = 1;
        int poseAlea;
        //private List<string> historique;
        int nbEssaisRestants;


        public MainWindow()
        {
            InitializeComponent();
        }
        private void initialisation()
        {
            tabMots = new string[] { "LUNDI", "ALTERNANCE", "LAPIN", "TUNISIE", "PROGRAMMATION", "NATATION", "DIMANCHE" };
            historique = new string[5];
        }
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            initialisation();
            nouvellePartie();
            nbPartie = 1;
            LBXHistorique.Items.Clear();
        }

        private String melanger(String chaine)
        {
            Random alea = new Random();
            StringBuilder chaineMelangee = new StringBuilder();
            foreach (char c in chaine)
            {
                int positionAlea = alea.Next(0, chaineMelangee.Length);
                chaineMelangee.Insert(positionAlea, c);
            }
            return chaineMelangee.ToString();
        }
        private void nouvellePartie()
        {
            //creation du mot alea
            Random randObj = new Random();
            poseAlea = randObj.Next(tabMots.Length);
            LBLAlphabet.Content = melanger(tabMots[poseAlea]);

            //sauvgardé les parties
            historique[nbPartie - 1] = tabMots[poseAlea];
            nbPartie++;
            //Mettre à jour l'hitorique

            //Initialisations
            TXTProposition.Text = "";
            LBLNbEssais.Content = NBMAX_ESSAIS.ToString();
            nbEssaisRestants = NBMAX_ESSAIS;
            LBXEssais.Items.Clear();   
        }
        private void motCorrect()
        {
            //mettre à jour l'historique des parties
            LBXHistorique.Items.Add("Partie " + nbPartie.ToString() + " | " + tabMots[poseAlea] + " | Gagnée en " + (NBMAX_ESSAIS - nbEssaisRestants) + " coup(s)");
            var Result = MessageBox.Show("Voulez vous rejouer?", "Gagné !!", MessageBoxButton.YesNo, MessageBoxImage.Question);
            if (Result == MessageBoxResult.Yes)
            {
                nouvellePartie();
            }
            else
            {
                Close();
            }
        }
        private void motIncorrect()
        {
            //mettre à jour l'historique des tentatives
            LBXEssais.Items.Add(TXTProposition.Text);
            if (nbEssaisRestants <= 0)//tous les coups ont été utilisés
            {
                //mettre à jour l'historique des parties
                LBXHistorique.Items.Add("Partie " + nbPartie.ToString() + " | " + tabMots[poseAlea] + " | Perdue en " + (NBMAX_ESSAIS - nbEssaisRestants) + " coups");
                var Result = MessageBox.Show("Le mot était " + tabMots[poseAlea] + ". Voulez vous rejouer ? ", "Perdu :( !!", MessageBoxButton.YesNo, MessageBoxImage.Question);
                if (Result == MessageBoxResult.No)
                {
                    Close();
                }
                else
                {
                    nouvellePartie();//rejouer
                }

            }
            else//Mettre à jour le nombre des coups restants
            {
                nbEssaisRestants -= 1;
                LBLNbEssais.Content = nbEssaisRestants.ToString();
            }

        }
        private void BTNTester_Click(object sender, RoutedEventArgs e)
        {
            if (TXTProposition.Text == "")
                MessageBox.Show("Veuillez saisir un mot!");
            else
            {
                if ((TXTProposition.Text).ToUpper() == tabMots[poseAlea])
                    motCorrect();
                else
                    motIncorrect();
            }
            
        }

        private void BTNQuitter_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }

    }
}
