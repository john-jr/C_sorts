using System;
using System.Windows.Input;
using Module3_Escola.ViewModels;

namespace Module3_Escola.Commands
{
    internal class FuncionarioUpdateCommand : ICommand
    {
        private FuncionarioViewModel viewModel;

        public FuncionarioUpdateCommand(FuncionarioViewModel viewModel)
        {
            this.viewModel = viewModel; 
        }



        #region Icommand Members
        public event EventHandler CanExecuteChanged
        {
            add { CommandManager.RequerySuggested += value; }
            remove { CommandManager.RequerySuggested -= value; }
        }
        public bool CanExecute(object parameter)
        {
            return String.IsNullOrWhiteSpace(viewModel.Funcionario.Error); 
        }

        public void Execute(object parameter)
        {
            viewModel.SalvarAlteracao();
        }
        #endregion

    }
}
