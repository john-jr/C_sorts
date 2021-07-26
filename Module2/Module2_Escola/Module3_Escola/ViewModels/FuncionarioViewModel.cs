using System;
using System.Diagnostics;
using System.Windows.Input;
using Module3_Escola.Commands;
using Module3_Escola.Models;
using Module3_Escola.Views;



namespace Module3_Escola.ViewModels
{
    internal class FuncionarioViewModel
    {
        private Funcionario funcionario;
        private FuncionarioInfoViewModel childViewModel;

        public FuncionarioViewModel()
        {
            funcionario = new Funcionario("Rodrigo");
            childViewModel = new FuncionarioInfoViewModel();
            UpdateCommand = new FuncionarioUpdateCommand(this);
        }

    

        public Funcionario Funcionario
        {
            get
            {
                return funcionario;
            }
        }

        public ICommand UpdateCommand
        {
            get;
            private set;
        }

        public void SalvarAlteracao()
        {
            FuncionarioInfoView view = new FuncionarioInfoView();
            view.DataContext = childViewModel;

            childViewModel.Info = Funcionario.Nome + " foi atualizado no BD";

            view.ShowDialog();

           
        }

    }
}
