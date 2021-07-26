using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel;

namespace Teste3_1.Model
{
    class ModeloTeste : INotifyPropertyChanged
    {
        private string texto;

        public ModeloTeste()
        {

        }

        public string Texto
        {
             get
            {
                return texto; 
            }
            set
            {
                texto = value;
                OnPropertyChanged("Texto");
            }
        }

        #region INotifyPropertyChanged
        public event PropertyChangedEventHandler PropertyChanged;
        private void OnPropertyChanged(string propertyName)
        {
            PropertyChangedEventHandler handler = PropertyChanged;
            if (handler != null)
            {
                handler(this, new PropertyChangedEventArgs(propertyName));
            }
        }
        #endregion


    }

}
