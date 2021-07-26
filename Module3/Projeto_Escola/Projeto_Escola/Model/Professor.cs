using System;
using System.ComponentModel;

namespace Projeto_Escola.Model
{
    class Professor : Funcionario, INotifyPropertyChanged
    {
        private String especialidade;


        public Professor()
        {
          
        }

        public string Especialidade
        {
            get
            {
                return this.especialidade;
            }
            set
            {
                this.especialidade = value;
                OnPropertyChanged("Especialidade");
            }
        }


        #region  INotifyPropertyChanged Members
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
