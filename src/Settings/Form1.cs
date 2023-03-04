namespace Settings
{
    public partial class Form1 : Form
    {
        private readonly string KEY_NF = "EnableNewFolderPlus";

        public Form1()
        {
            InitializeComponent();

        }

        protected override void OnShown(EventArgs e)
        {
            base.OnShown(e);
            var software = Microsoft.Win32.Registry.CurrentUser.CreateSubKey("Software");
            using (var key = software.CreateSubKey("anpho"))
            {
                using (var settings = key.CreateSubKey("ExplorerEnhancement"))
                {
                    var v = settings.GetValue(KEY_NF);
                    if (v != null)
                    {
                        cbNewFolder.Checked = ((int)v == 1);
                    }
                    else
                    {
                        settings.SetValue(KEY_NF, 1);
                        cbNewFolder.Checked = true;
                    }
                }
            }
            software.Close();

        }

        private void cbNewFolder_CheckedChanged(object sender, EventArgs e)
        {

            var software = Microsoft.Win32.Registry.CurrentUser.CreateSubKey("Software");
            using (var key = software.CreateSubKey("anpho"))
            {
                using (var settings = key.CreateSubKey("ExplorerEnhancement"))
                {
                    settings.SetValue(KEY_NF, cbNewFolder.Checked ? 1 : 0);
                }
            }
            software.Close();

        }
    }
}