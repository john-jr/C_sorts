using System;
using System.ComponentModel;

namespace Module2_Escola.Models
{
    class Funcionario : INotifyPropertyChanged
    {
        private string nome;
        //private TipoContrato contrato;
       //private double salario;

        public Funcionario(string nome)
        {
            this.nome = nome;
          //  this.contrato = contrato;
         //   this.salario = salario;
        }

        public String Nome
        {
            get
            {
                return nome;
            }
            set
            {
                nome = value;
                OnPropertyChanged("nome");
            }
        }
        internal enum TipoContrato
        {
            PJ = 1,
            CLT = 2
        }



        #region  INotifyPropertyChanged Members

        public event PropertyChangedEventHandler PropertyChanged;

        private void OnPropertyChanged(string propertyName)
        {
            PropertyChangedEventHandler handler = PropertyChanged;
            if(handler != null)
            {
                handler(this, new PropertyChangedEventArgs(propertyName));
            }

        }

        #endregion



   


    }
}
