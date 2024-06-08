# CSharp API
### Console
#### method
* **WriteLine("contents")** // 会换行  
* **Write("contents")** // 不换行  
* **ReadKey(true)** // wait for user press key, but do nothing after pressing  
* **ReadLine()** // return string...
#### property
* **Title** 
* **ForegroundColor**
* **BackgroundColor**

### DataTime
* **DataTime d1 = new DataTime(2010, 1, 22)** // Year, Month, Daty 
* **double days = (d2 - d1).TotalDays** 
* **.AddDays(int counts)**

### Random
        Random ran = new Random(System.Environment.TickCount);  
        ran.Next(1, 100); // 1~100

### Directory    System.IO namespace
* **GetFiles()** 列出所有文件
* **GetDirectories()** 列出文件夹下的所有子文件夹

* **Application.Run(new Form1());**

## GUI
#region #endregion 可以创建自定义折叠区  
* **Application.Run(new Form1());**

### 带图标的按钮
载入图片
**property** 双击->资源添加现有（导入资源）->在button的property的image  
**属性Flat、FlatAppearance**  

## Label
### property
* **Text**
* Click时间
* **Font/ForeColor** 字体与颜色
* **autosize** 自动伸缩
### 带图标的label
* **image** 属性指定图标
* **ImageAlign** 属性为中部靠左
* **TextAlign**  中部靠右
* **autosize** False，调整标签大小OK

## LinkLabel （自学） =  label + button

## TextBox

### property
* **Text**
* **TextChanged** 事件能够real time响应用户输入   
* **MultiLine、ScrollBars**
* 屏蔽掉非数字，与KeyDown、KeyPress ...

点击property的“闪电”，可以显示事件面板，列出了空间支持的所有list，双击其中一个事件，就会自动生成框架  
如果删除其中的框架，会出现错误，需要转到代码去消除  
或者右键**重置**  

## 进度条 ProgressBar
### main property
* **Maximum、Minimum**
* **Value（当前值**

## 时间控件 Timer
每隔多长时间调用一次，在property的interval(单位是毫秒)，enable是调用设置

ProgressBarAndTimer知道动态事件

## BackgroundWorker
https://www.cnblogs.com/sparkdev/p/5906272.html  
双击BackgroundWorker控件，会有DoWork事件

        private BackgroundWorker _demoBGWorker = new BackgroundWorker();
        _demoBGWorker.DoWork += BGWorker_DoWork;
        _demoBGWorker.RunWorkerAsync();
        private void BGWorker_DoWork(object sender, DoWorkEventArgs e)
        {
            //在这里执行耗时的运算。
            int sum = 0;
            for (int i = 0; i <= 100; i++)
            {
                sum += i;
            }
        }

## 动态按钮 MouseHover/Leave事件
鼠标移入移出

## 自学:单选按钮、复选按钮、数字输入控件(NumericUpDown) PictureBox

## 控件通用技巧
* **Enable** 
* **visible**
* **Anchor**
* **Dock**

## 容器控件 Form是顶层的容器
### 面板 Panel 可以放置其他控件
### 组合框 GroupBox 对于**多组**单选按钮的情况适用
### 选项卡控件 TabControl 
* 添加与移除在属性**TabPages**里操作
* 在代码里操作：   
        
        // addTab事件
        tabCount++;
        TabPage newPage = new TabPage("tabPage" + tabCount); //
        newPage.BackColor = Color.FromArgb(
            ran.Next(0, 255) // RGB
            , ran.Next(0, 255)
            , ran.Next(0, 255)
        );
        tabControl1.TabPages.Add(newPage); //添加到容器中

        // 激活
        if(tabControl1.SelectedIndex != 0) {
            tabControl1.SelectTab(tabControl1.SelectedIndex - 1);
        }

#### method
* tabControl.
* **.TabPages.Add(TabPage tb)** //
* **.SelectTab()**

### 分隔条m面板 SplitContainer
### FlowLayout
### TableLayoutPanel

## Form1.Show() // call的这个窗口可以被激活
## Form1.ShowDialog(); // call的这个主窗口不能被选中

## 在public后加override、virtual修饰符

## DataGridView
### method
#### 行列值操作(HeaderCell\Cell[1]\Cell[2]...)
***using dgv = dataGridView1***
* **dgv.Rows.Add();** // 添加新行，返回他的index
* **dgv.ColumnCount**
* **dgv.Rows[index1].Cells[index2].Value** // 这个value可以赋值，可以赋值给其他object
* **dgv.CurrentCell.Value** return current cell value
* **dgv.CurrentCell.ColumnIndex/RowIndex**
* **dgv.CurrentCellAddress.Y/X** Y:Row, X:Column
* **dgv.CurrentCell = dataGridView1[1, 0]** // 当前单元格可以通过DataGridView对象的CurrentCelll设定激活的单元格,设置为**null**可以取消激活
* **dgv.Columns/Rows[index].ReadOnly = true** // same as CurrentCell[x, y]
* **DataGridView1.Columns/Rows[0].HeaderCell.Value = "第一列"** //改变第一列/行头内容
* **DataGridView1.TopLeftHeaderCell.Value = "左上";** // 改变DataGridView1的左上头部单元内容 

#### ToolTip 浮显示的文字
DataGridView.ShowCellToolTips = True 的情况下， 单元格的 ToolTip 可以表示出来。对于单元格窄小，无法完全显示的单元格， ToolTip 可以显示必要的信息。  
1. 设定单元格的ToolTip内容   
// 设定单元格的ToolTip内容   
**DataGridView1[0, 0].ToolTipText = "该单元格的内容不能修改";**  
// 设定列头的单元格的ToolTip内容   
**DataGridView1.Columns[0].ToolTipText = "该列只能输入数字";**  
// 设定行头的单元格的ToolTip内容   
**DataGridView1.Rows[0].HeaderCell.ToolTipText = "该行单元格内容不能修改";**
2. CellToolTipTextNeeded 事件 
在批量的单元格的 ToolTip 设定的时候，一个一个指定那么设定的效率比较低， 这时候可以利用 CellToolTipTextNeeded 事件。当单元格的 ToolTipText 变化的时候也会引发该事件。但是，当DataGridView的DataSource被指定且VirualMode=True的时候，该事件不会被引发。   
// CellToolTipTextNeeded事件处理方法   

        private void DataGridView1_CellToolTipTextNeeded(object sender, 
            DataGridViewCellToolTipTextNeededEventArgs e) 
        { 
            e.ToolTipText = e.ColumnIndex.ToString() + ", " + e.RowIndex.ToString(); 
        }

#### 行/列的操作
DataGridView  不显示最下面的新行：
1. **DataGridView1.AllowUserToAddRows = false;** // 设置用户不能手动给 DataGridView1 添加新行,但是，可以通过程序:**DataGridViewRowCollection.Add** 为 DataGridView 追加新行。
2. 行、列的隐藏  
   **DataGridView1.Columns/Rows[0].Visible = false;** //第一行列
3. 行、列头的隐藏  
   **DataGridView1.Column/RowHeadersVisible = false;**
4. 行和列的删除   
// 删除名为"Column1"的列   
**DataGridView1.Columns.Remove("Column1");**   
// 删除第一列   
**DataGridView1.Columns/Rows.RemoveAt(0);**   

        // 删除选中行   
        foreach (DataGridViewRow r in DataGridView1.SelectedRows)   
        { 
            if (!r.IsNewRow) 
            { 
                DataGridView1.Rows.Remove(r); 
            } 
        }

5. 列冻结  
**DataGridView1.Columns[1].Frozen = True;**
6. **dgv.Rows[0].Selected = True;**
7. **dataGridView1.Rows.Clear();** 清空

## DataTable


## DataTable与DataGridView
DataGridView dgv;  
DataTable dt;
* dgv.DataSource = dt;
* Clear()在单元格的应用

## DataGridView to Excel

        //实例化一个Excel.Application对象   
        Microsoft.Office.Interop.Excel.Application excel = new Microsoft.Office.Interop.Excel.Application();
        //让后台执行设置为不可见，为true的话会看到打开一个Excel，然后数据在往里写  
        excel.Visible = true;
        //新增加一个工作簿，Workbook是直接保存，不会弹出保存对话框，加上Application会弹出保存对话框，值为false会报错  
        excel.Application.Workbooks.Add(true);
        //生成Excel中列头名称,EXCEL从1开始计数
        for (int i = 0; i < dataGridView1.Columns.Count; i++) {
            if (this.dataGridView1.Columns[i].Visible==true) {
                excel.Cells[1, i + 1] = dataGridView1.Columns[i].HeaderText;
            }
        }
        //把DataGridView当前页的数据保存在Excel中  
        for (int i = 0; i < dataGridView1.Rows.Count - 1; i++) 
        {
            System.Windows.Forms.Application.DoEvents();
            for (int j = 0; j < dataGridView1.Columns.Count; j++) 
            {
                if (this.dataGridView1.Columns[j].Visible==true) 
                {
                    if (dataGridView1[j, i].ValueType == typeof(string)) 
                    {
                        excel.Cells[i + 2, j + 1] = "'" + dataGridView1[j, i].Value.ToString();
                    } 
                    else 
                    {
                        excel.Cells[i + 2, j + 1] = dataGridView1[j, i].Value.ToString();
                    }
                }
            }
        }
         //设置禁止弹出保存和覆盖的询问提示框  
        excel.DisplayAlerts = false;
        excel.AlertBeforeOverwriting = false;
         //保存工作簿  
        excel.Application.Workbooks.Add(true).Save();
        //保存excel文件  
        excel.Save("D:" + "\\KKHMD.xls");

        //确保Excel进程关闭  
        excel.Quit();
        excel = null;
        GC.Collect();//如果不使用这条语句会导致excel进程无法正常退出，使用后正常退出
        MessageBox.Show(this,"文件已经成功导出！","信息提示");

        catch (Exception ex)
        {
            MessageBox.Show(ex.Message, "错误提示");
        }

    }

### 另外一个实现
        private void btnExport_Click(object sender, EventArgs e) //点击导出到Excel表按钮
        {
            string fileName = "";
            string saveFileName = "";
            SaveFileDialog saveDialog = new SaveFileDialog();
            saveDialog.DefaultExt = "xlsx";
            saveDialog.Filter = "Excel文件|*.xlsx";
            saveDialog.FileName = fileName;
            saveDialog.ShowDialog();
            saveFileName = saveDialog.FileName;
            if (saveFileName.IndexOf(":") < 0) return; //被点了取消
            Microsoft.Office.Interop.Excel.Application xlApp = new Microsoft.Office.Interop.Excel.Application();
            if (xlApp == null)
            {
                MessageBox.Show("无法创建Excel对象，您的电脑可能未安装Excel");
                return;
            }
            Microsoft.Office.Interop.Excel.Workbooks workbooks = xlApp.Workbooks;
            Microsoft.Office.Interop.Excel.Workbook workbook = workbooks.Add(Microsoft.Office.Interop.Excel.XlWBATemplate.xlWBATWorksheet);
            Microsoft.Office.Interop.Excel.Worksheet worksheet = (Microsoft.Office.Interop.Excel.Worksheet)workbook.Worksheets[1];//取得sheet1 
            //写入标题             
            for (int i = 0; i < dataGridView1.ColumnCount; i++)
            { worksheet.Cells[1, i + 1] = dataGridView1.Columns[i].HeaderText; }
            //写入数值
            for (int r = 0; r < dataGridView1.Rows.Count; r++)
            {
                for (int i = 0; i < dataGridView1.ColumnCount; i++)
                {
                    worksheet.Cells[r + 2, i + 1] = dataGridView1.Rows[r].Cells[i].Value;
                }
                System.Windows.Forms.Application.DoEvents();
            }
            worksheet.Columns.EntireColumn.AutoFit();//列宽自适应
            MessageBox.Show(fileName + "资料保存成功", "提示", MessageBoxButtons.OK);
            if (saveFileName != "")
            {
                try
                {
                    workbook.Saved = true;
                    workbook.SaveCopyAs(saveFileName);  //fileSaved = true;                 
                }
                catch (Exception ex)
                {//fileSaved = false;                      
                    MessageBox.Show("导出文件时出错,文件可能正被打开！\n" + ex.Message);
                }
            }
            xlApp.Quit();
            GC.Collect();//强行销毁           
        }

## 弹出文件查找框 OpenFileDialog
        OpenFileDialog fd = new OpenFileDialog();
        fd.Filter = "EXCEL文件(*.xls)|*.xls|EXCEL文件(*.xlsx)|*.xlsx"; // 提示1|类型1
        if (fd.ShowDialog() == DialogResult.OK)
        {
            //这里面就可以对选择的文件进行处理了
        }

         OpenFileDialog fd = new OpenFileDialog();//首先根据打开文件对话框，选择excel表格
            ofd.Filter = "表格|*.xls";//打开文件对话框筛选器
            string strPath;//文件完整的路径名
            if (ofd.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    strPath = ofd.FileName;
                    string strCon = "provider=microsoft.jet.oledb.4.0;data source=" + strPath + ";extended properties=excel 8.0";//关键是红色区域
                    OleDbConnection Con = new OleDbConnection(strCon);//建立连接
                    string strSql = "select * from [Sheet1$]";//表名的写法也应注意不同，对应的excel表为sheet1，在这里要在其后加美元符号$，并用中括号
                    OleDbCommand Cmd = new OleDbCommand(strSql, Con);//建立要执行的命令
                    OleDbDataAdapter da = new OleDbDataAdapter(Cmd);//建立数据适配器
                    DataSet ds = new DataSet();//新建数据集
                    da.Fill(ds, "shyman");//把数据适配器中的数据读到数据集中的一个表中（此处表名为shyman，可以任取表名）
                    //指定datagridview1的数据源为数据集ds的第一张表（也就是shyman表），也可以写ds.Table["shyman"]

　　　　　　　dataGridView1.DataSource = ds.Tables[0];
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);//捕捉异常
                }
            }

## 保存对话框 SaveFileDialog
        SaveFileDialog sfd = new SaveFileDialog();  
        sfd.Filter = @"文本文件|*.txt";  
        sfd.ShowDialog();  
        textBox1.Text = sfd.FileName;  

## Message
* **MessageBox.Show("contents", "caption", "Button");**
* **MessageBoxButtons.OK** // 一个OK
* **MessageBoxButtons.OKCancel** // OK 和 取消两个按钮，可以在下列执行：

## DialogResult
        DialogResult dr = MessageBox.Show("contents"
            , "提示"
            , MessageBoxButtons.OKCancel
            , MessageBoxIcon.Question);
        if (dr == DialogResult.OK)
        {
            //点确定的代码
        }
        else
        { 
            //点取消的代码        
        }
