using System;
using System.ComponentModel;

namespace Module3_Escola.Models
{
    public class Funcionario : INotifyPropertyChanged, IDataErrorInfo
    {
        private String nome;

        public Funcionario(String nomeFuncionario)
        {
            Nome = nomeFuncionario;
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
                OnPropertyChanged("Nome");
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

        #region IDataErrorInfo Members
        public string Error
        {
            get;
            private set;

        }
        public string this[string columnName]{
            get{
                if(columnName == "Nome")
                {
                    if (String.IsNullOrWhiteSpace(Nome))
                    {
                        Error = "O Nome não pode estar vazio";
                    }
                    else
                    {
                        Error = null;
                    }
                }
                return Error;

            }
        }
        #endregion
    }
}

