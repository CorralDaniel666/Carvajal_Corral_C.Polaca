using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.IO;
using AgentObjects;
using AxAgentObjects;
using System.Threading;

namespace WinAppMSAgentsManagement
{
    public partial class frmAgentManagement : Form
    {
        private CAgent mObjAgent;
        public frmAgentManagement()
        {
            InitializeComponent();
        }

        public void LoadAgent()
        {
            //mObjAgent = new CAgent("merlin", this, 400, 200);
            //mObjAgent = new CAgent("Genie", this, 400, 200);
            mObjAgent = new CAgent("Peedy", this, 400, 200);
            //mObjAgent = new CAgent("Robby", this, 400, 200);
            
            mObjAgent.ShowAgent(this);
            mObjAgent.IniciarBienvenida(this);
        }

        private void frmAgentManagement_Load(object sender, EventArgs e)
        {
            LoadAgent();
        }
    }
}
