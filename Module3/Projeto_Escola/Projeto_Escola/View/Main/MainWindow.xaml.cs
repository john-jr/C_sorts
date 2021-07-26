using System;
using System.Windows;
using Projeto_Escola.ViewModel.Funcionarios;


namespace Projeto_Escola
{
    /// <summary>
    /// Interação lógica para MainWindow.xam
    /// </summary>
    public partial class MainWindow : Window
    {
        MenuFuncionarioViewModel ViewModel;
        public MainWindow()
        {
            InitializeComponent();
            ViewModel = new MenuFuncionarioViewModel();
            this.DataContext = ViewModel;
        }  
    }
}
