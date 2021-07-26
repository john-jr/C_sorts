using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using Module2_Escola.ViewModels;

namespace Module2_Escola.Views
{
    /// <summary>
    /// Lógica interna para EditarFuncionario.xaml
    /// </summary>
    public partial class EditarFuncionario : Window
    {
        public EditarFuncionario()
        {
            InitializeComponent();
            DataContext = new FuncionarioViewModel();
        }
    }
}
