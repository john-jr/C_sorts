using System;
using System.ComponentModel;

namespace Projeto_Escola.Model
{
    public class Funcionario : INotifyPropertyChanged
    {
        private int id;
        private String nome;
        private String cpf;
        private Double salario;

        

        public int Id
        {
            get
            {
                return id;
            }
            set
            {
                id = value;
                OnPropertyChanged("Id");
            }
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
        public String Cpf
        {
            get
            {
                return cpf;
            }
            set
            {
                cpf = value;
                OnPropertyChanged("Cpf");
            }
        }
        public Double Salario
        {
            get
            {
                return salario;
            }
            set
            {
                salario = value;
                OnPropertyChanged("Salario");
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
