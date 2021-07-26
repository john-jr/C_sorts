using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel;
using System.Windows.Input;
using Teste3_1.Commands;
using System.Collections.ObjectModel;
using System.Collections.Specialized;
using System.Runtime.CompilerServices;

namespace Teste3_1.ViewModel
{
    class MainWIndowViewModel : INotifyPropertyChanged
    {
        public ICommand AddItemIntoList { get; private set;}
        public List<string> stringList { get; private set;}
        public string text { get; private set; }

        int test = 0;

        #region INotifyPropertyChanged
        public event PropertyChangedEventHandler PropertyChanged;
        private void RaisePropertyChanged(string prop = "")
        {
            if (PropertyChanged != null)
                PropertyChanged(this, new PropertyChangedEventArgs(prop));
        }
        #endregion INotifyCollectionChanged




        public MainWIndowViewModel()
        {
            stringList = new List<string>();
            text = "AFA";
            CreateCommands();
            stringList.Add("ADD");
        }
       


        private void CreateCommands()
        {
            
            AddItemIntoList = new RelayCommand(
                (param) =>
                {
                    test++;
                    RaisePropertyChanged("stringList");
                    stringList.Add("Saúde"+test);
                    stringList = new List<string>(stringList);
                    if (text.Equals("AFA")) {
                        text = "RAFA";
                    }
                    else
                    {
                        text = "AFA";
                    }
                    RaisePropertyChanged("text");
                    RaisePropertyChanged("stringList");
                },   
                (param) =>
                {
                    return true;
                }
                );

        }



        private string texto;
        public string Texto
        {
            get { return this.texto; }
            set
            {
                this.texto = value + "#1";
                this.RaisePropertyChanged("Texto");
            }
        }

    }
}
