using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Windows.Forms;
using AgentObjects;
using AxAgentObjects;
using System.IO;
using System.Threading;

namespace WinAppMSAgentsManagement
{
    class CAgent
    {
        #region Atributes of the class
        ///<summary>
        ///Datos o variables miembro
        ///</summary>

        private AxAgent mMSAgent = new AxAgent();
        private string mName;
        private int mX, mY;
        private int mVoice;
        private int mCadence;
        private string texto;
        #endregion

        #region Propiedades
        ///<summary>
        ///Manejo de descriptores de acceso
        ///</summary>   

        public AxAgent MSAgente
        {
            get { return mMSAgent; }
            set { mMSAgent = value; }
        }

        public string Name
        {
            get { return mName; }
            set { mName = value; }
        }

        public int X
        {
            get { return mX; }
            set { mX = value; }
        }

        public int Y
        {
            get { return mY; }
            set { mY = value; }
        }

        public int Voice
        {
            get { return mVoice; }
            set { mVoice = value; }
        }

        public int Cadence
        {
            get { return mCadence; }
            set { mCadence = value; }
        }

        #endregion

        #region Builders of the Class
        ///<summary>
        /// Constructores
        ///</summary>

        // Constructor por defecto
        public CAgent()
        {

        }

        public CAgent(string Name, Form ObjForm, int xBegin, int yEnd)
        {
            mCadence = 75;//100;
            mVoice = 200;
            mX = xBegin;
            mY = yEnd;
            mName = Name;
            mMSAgent.BeginInit();
            ObjForm.Controls.Add(mMSAgent);
            mMSAgent.EndInit();
            mMSAgent.Characters.Load(mName, mName + ".acs");
            ChooseLanguage(true);
            mMSAgent.BringToFront();
        }

        #endregion

        #region Methods
        ///<summary>
        ///Funciones miembro
        ///</summary>  
        ///

        public void LeerTexto() {
            using (StreamReader read = new StreamReader(@"C:\Users\Administrador1\Desktop\pp1\Carvajal_Corral_C.Polaca\Carvajal_Corral_C.Polaca\ProyectoPolaca\ProyectoPolaca\respaldo.txt")) 
            {
                while (!read.EndOfStream)
                {
                    texto = read.ReadLine();
                }
          
            }
         
        }

        public void ChooseLanguage(Boolean op)
        {
            if (op == true)
            {
                // Idioma Español
                mMSAgent.Characters[mName].LanguageID = 3082;
            }
            else
            {
                // Idioma Inglés
                mMSAgent.Characters[mName].LanguageID = 0x409;
            }
        }

        public void ChooseVoice(int tone)
        {
            mVoice = tone;
        }

        public void setCadence(int Cadence)
        {
            mCadence = Cadence;
        }

        public void GoStartPosition(Form formulario)
        {
            mMSAgent.Characters[mName].MoveTo(100, 100, mCadence);
        }

        public void HideAgent()
        {
            StopAgent();
            mMSAgent.Characters[mName].Hide(null);
        }

        public void FireAgent()
        {
            StopAgent();
            mMSAgent.Characters[mName].Play("Wave");
        }

        public void StopAgent()
        {
            mMSAgent.Characters[mName].StopAll("Play");
            mMSAgent.Characters[mName].StopAll("Speak");
            mMSAgent.Characters[mName].StopAll("Move");
        }

        public void ShowAgent(Form formulario)
        {
            StopAgent();
            mMSAgent.BringToFront();
            //agente.Characters[Name].MoveTo((short)(formulario.DesktopLocation.X + x), (short)(formulario.DesktopLocation.Y + y), Cadence);
            mMSAgent.Characters[mName].MoveTo(50, 50, mCadence);
            //agente.Characters[Name].MoveTo(50, 50, 0);
            mMSAgent.Characters[mName].Show(null);
        }

        public void IniciarBienvenida(Form ObjForm)
        {
            LeerTexto();
            mMSAgent.Characters[mName].Balloon.Style = 3;
            mMSAgent.Characters[mName].Play("Greet");
            mMSAgent.Characters[mName].Play("Announce");
           // mMSAgent.Characters[mName].Speak("\\pit=" + Voice + "\\ Bievenido al Akinator", null);
            mMSAgent.Characters[mName].Speak(texto, null);
            mMSAgent.Characters[mName].Play("Blink");

            //mMSAgent.Characters[mName].MoveTo(100, 300, mCadence);
            //mMSAgent.Characters[mName].Play("GestureLeft");
            //mMSAgent.Characters[mName].Speak("Para jugar, debes pensar en uno de estos animales, " +
            //                                    "y yo intentaré adivinarlo.", null);
            //mMSAgent.Characters[mName].Play("DoMagic1");
            //mMSAgent.Characters[mName].Play("DoMagic2");
            Thread.Sleep(12000);
            ObjForm.Close();
            
        }

        public void LeerPregunta(Form ObjForm, Label lblPregunta, short x, short y)
        {
            StopAgent();
            mMSAgent.Characters[mName].Balloon.Style = 3;
            mX = x;
            mY = y;
            mMSAgent.Characters[mName].MoveTo((short)mX, (short)mY, mCadence);
            mMSAgent.Characters[mName].Play("GestureRight");
            mMSAgent.Characters[mName].Speak(lblPregunta.Text, null);
            mMSAgent.Characters[mName].Play("DoMagic1");
            mMSAgent.Characters[mName].Play("DoMagic2");
        }

        public void LeerTexto(Form ObjForm, string texto, short x, short y)
        {
            StopAgent();
            mMSAgent.Characters[mName].Balloon.Style = 3;
            mX = x;
            mY = y;
            mMSAgent.Characters[mName].MoveTo((short)mX, (short)mY, mCadence);
            mMSAgent.Characters[mName].Play("GestureRight");
            mMSAgent.Characters[mName].Speak(texto, null);
            mMSAgent.Characters[mName].Play("DoMagic1");
            mMSAgent.Characters[mName].Play("DoMagic2");
        }

        #endregion
    }
}
