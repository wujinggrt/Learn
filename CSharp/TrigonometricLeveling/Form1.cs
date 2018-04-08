using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TrigonometricLeveling
{
    public partial class Form1 : Form
    {
        private List<bool> columnStatus = new List<bool>(5);

        public Form1()
        {
            InitializeComponent();
            AddRow();
            SetFormat();
        }

        private void SetFormat()
        {
            dataGridView1.AllowUserToAddRows = false;
            dataGridView1.RowHeadersVisible = false;
            dataGridView1.AllowUserToResizeColumns = false;
            dataGridView1.AllowUserToResizeRows = false;
            dataGridView1.ReadOnly = false;
        }

        private int AddRow()
        {
            int y = dataGridView1.Rows.Add();
            dataGridView1.Rows[y].Cells[5].ReadOnly = true;
            return y;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            AddRow();
        }

        // enter事件
        private void dataGridView1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                bool status = InputCheck();
                if (status)
                {
                    Compute();
                    dataGridView1.CurrentRow.ReadOnly = true;
                    // 选中新建行的行首
                    int y = AddRow();
                    dataGridView1.CurrentCell = dataGridView1[0, y];
                }
                e.Handled = true;
            }
        }

        private void calculateButton_Click(object sender, EventArgs e)
        {
            bool status = InputCheck();
            if (status)
            {
                Compute();
                dataGridView1.CurrentRow.ReadOnly = true;
                // 选中新建行的行首
                int y = AddRow();
                dataGridView1.CurrentCell = dataGridView1[0, y];
            }   
        }

        private bool InputCheck()
        {
            columnStatus.Clear();
            for(int i = 0; i < dataGridView1.ColumnCount - 1; ++i)
            {
                // 空的情况
                if (dataGridView1.CurrentRow.Cells[i].Value == null)
                {
                    columnStatus.Add(false);
                    continue;
                }
                double temp = 0.0;
                string data = dataGridView1.CurrentRow.Cells[i].Value.ToString();
                if (!double.TryParse(data, out temp))
                {
                    columnStatus.Add(false);
                    continue;
                }
                else
                {
                    columnStatus.Add(true);
                    continue;
                }
            }
            string indexStr = "";
            bool allStatus = true;
            for (int i = 0; i < columnStatus.Count; ++i)
            {
                if (!columnStatus[i])
                {
                    allStatus = false;
                    indexStr += i + 1 + " ";
                }
            }
            if (!allStatus)
            {
                MessageBox.Show("以下格子数据错误！\n" + indexStr, "错误", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return false;
            }
            return true;
        }

        private void Compute()
        {
            var currentRow = dataGridView1.CurrentRow;
            double beginHeight = double.Parse(
                currentRow.Cells[0].Value.ToString());
            double verticalAngle = double.Parse(
                currentRow.Cells[1].Value.ToString());
            double distance = double.Parse(
                currentRow.Cells[2].Value.ToString());
            double instrumentHeight = double.Parse(
                currentRow.Cells[3].Value.ToString());
            double targetHeight = double.Parse(
                currentRow.Cells[4].Value.ToString());
            double endHeight =
                beginHeight +
                distance * Math.Tan(RadianTransform(verticalAngle)) +
                instrumentHeight -
                targetHeight;
            currentRow.Cells[5].Value = endHeight.ToString("f3");
        }

        private double RadianTransform(double angle)
        {
            double degree = (int)angle;
            double minute = (int)((angle - degree) * 100);
            double second = (int)((angle - degree) * 100 - minute) *100;
            double ret = (degree + minute / 60 + second / 3600) / 180 * Math.PI;
            return ret;
        }

        private void deleteButton_Click(object sender, EventArgs e)
        {
            if(dataGridView1.CurrentRow != null)
            {
                dataGridView1.Rows.Remove((dataGridView1.CurrentRow));
            }
            // 当行为空的时候，自动添加一行
            if(dataGridView1.RowCount == 0)
            {
                AddRow();
            }
        }

        private void clearButton_Click(object sender, EventArgs e)
        {
            dataGridView1.Rows.Clear();
            AddRow();
        }
    }
}
