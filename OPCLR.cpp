#include "pch.h"
#include "OPCLR.h"

namespace OPCLR {

	static libop op;

	static const wchar_t* StringToWchar(String^ value)
	{
		auto str = (wchar_t*)(void*)Marshal::StringToHGlobalUni(value);
		return str;
	}

	static const std::string ToCPPString(String^ value)
	{
		std::string str = marshal_as<std::string>(value->ToString());
		return str;
	}

	static String^ ToNetString(std::string value)
	{
		String^ str = gcnew String(value.c_str());
		return str;
	}

	static String^ WStringToString(wstring value)
	{
		String^ str = gcnew String(value.c_str());
		return str;
	}


	String^ OPSoft::Ver()
	{
		auto a = op.Ver();
		return gcnew String(a.c_str());
	}

	int OPSoft::SetPath(String^ path)
	{
		auto str = StringToWchar(path);

		long ret;
		op.SetPath(str, &ret);
		return ret;
	}

	String^ OPSoft::GetPath()
	{
		wstring str;
		op.GetPath(str);
		return WStringToString(str);
	}

	String^ OPSoft::GetBasePath()
	{
		wstring str;
		op.GetBasePath(str);
		return WStringToString(str);
	}

	int OPSoft::GetID()
	{
		long ret;
		op.GetID(&ret);
		return ret;
	}

	int OPSoft::GetLastError()
	{
		long ret;
		op.GetLastError(&ret);
		return ret;
	}

	//�����Ƿ񵯳�������Ϣ,Ĭ���Ǵ� 0:�رգ�1:��ʾΪ��Ϣ��2:���浽�ļ�,3:�������׼���
	int OPSoft::SetShowErrorMsg(long show_type)
	{
		long ret;
		op.SetShowErrorMsg(show_type, &ret);
		return ret;
	}

	//sleep
	int OPSoft::Sleep(long millseconds)
	{
		long ret;
		op.Sleep(millseconds, &ret);
		return ret;
	}
	//Process
	//inject dll
	int OPSoft::InjectDll(String^ process_name, String^ dll_name) {
		long ret;
		op.InjectDll(StringToWchar(process_name), StringToWchar(dll_name), &ret);
		return ret;
	}
	//�����Ƿ������߹رղ���ڲ���ͼƬ�������
	int OPSoft::EnablePicCache(long enable) {
		long ret;
		op.EnablePicCache(enable, &ret);
		return ret;
	}
	//ȡ�ϴβ�����ͼɫ���򣬱���Ϊfile(24λλͼ)
	int OPSoft::CapturePre(String^ file_name) { return 0; }

	int OPSoft::SetScreenDataMode(long mode) { return 0; }

	//---------------------algorithm-------------------------------
	//A���㷨
	String^ OPSoft::AStarFindPath(long mapWidth, long mapHeight, String^ disable_points, long beginX, long beginY, long endX, long endY) { return ""; }
	//
	String^ OPSoft::FindNearestPos(String^ all_pos, long type, long x, long y) { return ""; }
	//--------------------windows api------------------------------
	//����ָ������,ö��ϵͳ�з��������Ĵ���
	String^ OPSoft::EnumWindow(long parent, String^ title, String^ class_name, long filter) { return ""; }
	//����ָ�������Լ���������,ö��ϵͳ�з��������Ĵ���
	String^ OPSoft::EnumWindowByProcess(String^ process_name, String^ title, String^ class_name, long filter) { return ""; }
	//����ָ��������,ö��ϵͳ�з��������Ľ���PID
	String^ OPSoft::EnumProcess(String^ name) { return ""; }
	//�Ѵ�������ת��Ϊ��Ļ����
	int OPSoft::ClientToScreen(long ClientToScreen, long* x, long* y, long* bret) { return 0; }
	//���ҷ����������߱������Ķ���ɼ�����
	int OPSoft::FindWindow(String^ class_name, String^ title)
	{
		long ret;
		op.FindWindow(StringToWchar(class_name), StringToWchar(title), &ret);
		return ret;
	}
	//����ָ���Ľ������֣������ҿɼ�����
	int OPSoft::FindWindowByProcess(String^ process_name, String^ class_name, String^ title) { return 0; }
	//����ָ���Ľ���Id�������ҿɼ�����
	int OPSoft::FindWindowByProcessId(long process_id, String^ class_name, String^ title) { return 0; }
	//���ҷ����������߱������Ķ���ɼ�����,���ָ����parent,����parent�ĵ�һ���Ӵ����в���
	int OPSoft::FindWindowEx(long parent, String^ class_name, String^ title)
	{
		long ret;
		op.FindWindowEx(parent, StringToWchar(class_name), StringToWchar(title), &ret);
		return ret;
	}
	//��ȡ���ڿͻ���������Ļ�ϵ�λ��
	int OPSoft::GetClientRect(long hwnd, long* x1, long* y1, long* x2, long* y2) { return 0; }
	//��ȡ���ڿͻ�����Ŀ�Ⱥ͸߶�
	int OPSoft::GetClientSize(long hwnd, long* width, long* height) { return 0; }
	//��ȡ���������о������뽹��Ĵ��ھ��
	int OPSoft::GetForegroundFocus() { return 0; }
	//��ȡ��������,���Ի�ȡ�������Դ�����޷���ȡ���ľ��
	int OPSoft::GetForegroundWindow() { return 0; }
	//��ȡ���ָ��Ŀɼ����ھ��
	int OPSoft::GetMousePointWindow() { return 0; }
	//��ȡ��������Ŀɼ����ھ��
	int OPSoft::GetPointWindow(long x, long y) { return 0; }
	//����ָ����pid��ȡ������ϸ��Ϣ
	String^ OPSoft::GetProcessInfo(long pid) { return ""; }
	//��ȡ���ⴰ��
	int OPSoft::GetSpecialWindow(long flag) { return 0; }
	//��ȡ����������صĴ��ھ��
	int OPSoft::GetWindow(long hwnd, long flag) { return 0; }
	//��ȡ���ڵ�����
	String^ OPSoft::GetWindowClass(long hwnd) { return ""; }
	//��ȡָ���������ڵĽ���ID
	int OPSoft::GetWindowProcessId(long hwnd) { return 0; }
	//��ȡָ���������ڵĽ��̵�exe�ļ�ȫ·��
	String^ OPSoft::GetWindowProcessPath(long hwnd) { return ""; }
	//��ȡ��������Ļ�ϵ�λ��
	int OPSoft::GetWindowRect(long hwnd, long* x1, long* y1, long* x2, long* y2) { return 0; }
	//��ȡָ�����ڵ�һЩ����
	int OPSoft::GetWindowState(long hwnd, long flag) { return 0; }
	//��ȡ���ڵı���
	String^ OPSoft::GetWindowTitle(long hwnd) {
		wstring ret;
		op.GetWindowTitle(hwnd, ret);
		return WStringToString(ret);
	}
	//�ƶ�ָ�����ڵ�ָ��λ��
	int OPSoft::MoveWindow(long hwnd, long x, long y) { return 0; }
	//����Ļ����ת��Ϊ��������
	int OPSoft::ScreenToClient(long hwnd, long* x, long* y) { return 0; }
	//��ָ�����ڷ���ճ������
	int OPSoft::SendPaste(long hwnd) { return 0; }
	//���ô��ڿͻ�����Ŀ�Ⱥ͸߶�
	int OPSoft::SetClientSize(long hwnd, long width, long hight) {
		long ret;
		op.SetClientSize(hwnd, width, hight, &ret);
		return ret;
	}
	//���ô��ڵ�״̬
	int OPSoft::SetWindowState(long hwnd, long flag) {
		long ret;
		op.SetWindowState(hwnd, flag, &ret);
		return ret;
	}
	//���ô��ڵĴ�С
	int OPSoft::SetWindowSize(long hwnd, long width, long height) {
		long ret;
		op.SetWindowSize(hwnd, width, height, &ret);
		return ret;
	}
	//���ô��ڵı���
	int OPSoft::SetWindowText(long hwnd, String^ title) {
		long ret;
		op.SetWindowText(hwnd, StringToWchar(title), &ret);
		return ret;
	}
	//���ô��ڵ�͸����
	int OPSoft::SetWindowTransparent(long hwnd, long trans) { return 0; }
	//��ָ�����ڷ����ı�����
	int OPSoft::SendString(long hwnd, String^ str) { return 0; }
	//��ָ�����ڷ����ı�����-���뷨
	int OPSoft::SendStringIme(long hwnd, String^ str) { return 0; }
	//���п�ִ���ļ�,��ָ��ģʽ
	int OPSoft::RunApp(String^ cmdline, long mode) { return 0; }
	//���п�ִ���ļ�����ָ����ʾģʽ
	int OPSoft::WinExec(String^ cmdline, long cmdshow) { return 0; }

	//���������в����ؽ��
	String^ OPSoft::GetCmdStr(String^ cmd, long millseconds) { return ""; }

	//--------------------Background -----------------------
	//bind window and beign capture screen
	int OPSoft::BindWindow(long hwnd, String^ display, String^ mouse, String^ keypad, long mode) 
	{ 
		long ret;
		op.BindWindow(hwnd,StringToWchar(display), StringToWchar(mouse), StringToWchar(keypad),mode,&ret);
		return ret;
	}
	//
	int OPSoft::UnBindWindow() 
	{ 
		long ret;
		op.UnBindWindow(&ret);
		return ret;
	}
	//--------------------mouse & keyboard------------------
	//��ȡ���λ��.
	String^ OPSoft::GetCursorPos() {
		long x;
		long y;
		long ret;
		op.GetCursorPos(&x, &y, &ret);
		auto str = std::to_string(x) + "-" + std::to_string(y);

		return ToNetString(str);
	}

	//���������ϴε�λ���ƶ�rx,ry.
	int OPSoft::MoveR(long x, long y) {
		long ret;
		op.MoveR(x, y, &ret);
		return ret;
	}
	//������ƶ���Ŀ�ĵ�(x,y)
	int OPSoft::MoveTo(long x, long y)
	{
		long ret;
		op.MoveTo(x, y, &ret);
		return ret;
	};
	//������ƶ���Ŀ�ķ�Χ�ڵ�����һ��
	int OPSoft::MoveToEx(long x, long y, long w, long h)
	{

		long ret;
		op.MoveToEx(x, y, w, h, &ret);
		return ret;
	}

	//����������
	int OPSoft::LeftClick()
	{
		long ret;
		op.LeftClick(&ret);
		return ret;
	}

	//˫��������
	int OPSoft::LeftDoubleClick()
	{
		long ret;
		op.LeftDoubleClick(&ret);
		return ret;
	}
	//��ס������
	int OPSoft::LeftDown()
	{
		long ret;
		op.LeftDown(&ret);
		return ret;
	}
	//����������
	int OPSoft::LeftUp()
	{
		long ret;
		op.LeftUp(&ret);
		return ret;
	}
	//��������м�
	int OPSoft::MiddleClick()
	{
		long ret;
		op.MiddleClick(&ret);
		return ret;
	}
	//��ס����м�
	int OPSoft::MiddleDown()
	{
		long ret;
		op.MiddleDown(&ret);
		return ret;
	}
	//��������м�
	int OPSoft::MiddleUp()
	{
		long ret;
		op.MiddleUp(&ret);
		return ret;
	}
	//��������Ҽ�
	int OPSoft::RightClick()
	{
		long ret;
		op.RightClick(&ret);
		return ret;
	}
	//��ס����Ҽ�
	int OPSoft::RightDown()
	{
		long ret;
		op.RightDown(&ret);
		return ret;
	}
	//��������Ҽ�
	int OPSoft::RightUp()
	{
		long ret;
		op.RightUp(&ret);
		return ret;
	}
	//�������¹�
	int OPSoft::WheelDown()
	{
		long ret;
		op.WheelDown(&ret);
		return ret;
	}
	//�������Ϲ�
	int OPSoft::WheelUp()
	{
		long ret;
		op.WheelUp(&ret);
		return ret;
	}
	//��ȡָ���İ���״̬.(ǰ̨��Ϣ,���Ǻ�̨)
	int OPSoft::GetKeyState(long vk_code)
	{
		long ret;
		op.GetKeyState(vk_code, &ret);
		return ret;
	}
	//��סָ�����������
	int OPSoft::KeyDown(long vk_code)
	{
		long ret;
		op.KeyDown(vk_code, &ret);
		return ret;
	}
	//��סָ�����������
	int OPSoft::KeyDownChar(String^ vk_code)
	{
		long ret;
		op.KeyDownChar(StringToWchar(vk_code), &ret);
		return ret;
	}
	//�����������vk_code
	int OPSoft::KeyUp(long vk_code)
	{
		long ret;
		op.KeyUp(vk_code, &ret);
		return ret;
	}
	//�����������vk_code
	int OPSoft::KeyUpChar(String^ vk_code)
	{
		long ret;
		op.KeyUpChar(StringToWchar(vk_code), &ret);
		return ret;
	}
	//�ȴ�ָ���İ������� (ǰ̨,���Ǻ�̨)
	int OPSoft::WaitKey(long vk_code, long time_out)
	{
		long ret;
		op.WaitKey(vk_code, time_out, &ret);
		return ret;
	}
	//�����ַ���
	//long SendString(long HWND)
	//�����������vk_code
	int OPSoft::KeyPress(long vk_code)
	{
		long ret;
		op.KeyPress(vk_code, &ret);
		return ret;
	}
	int OPSoft::KeyPressChar(String^ vk_code)
	{
		long ret;
		op.KeyPressChar(StringToWchar(vk_code), &ret);
		return ret;
	}

	//--------------------image and color-----------------------
	//ץȡָ������(x1, y1, x2, y2)��ͼ��, ����Ϊfile
	int OPSoft::Capture(long x1, long y1, long x2, long y2, String^ file_name) { return 0; }
	//�Ƚ�ָ�������(x,y)����ɫ
	int OPSoft::CmpColor(long x, long y, String^ color, double sim) { return 0; }
	//����ָ�������ڵ���ɫ
	int OPSoft::FindColor(long x1, long y1, long x2, long y2, String^ color, double sim, long dir, long* x, long* y) { return 0; }
	//����ָ�������ڵ�������ɫ
	String^ OPSoft::FindColorEx(long x1, long y1, long x2, long y2, String^ color, double sim, long dir) { return ""; }
	//����ָ���Ķ�������ɫ����
	int OPSoft::FindMultiColor(long x1, long y1, long x2, long y2, String^ first_color, String^ offset_color, double sim, long dir, long* x, long* y) { return 0; }
	//����ָ���Ķ�����������ɫ����
	String^ OPSoft::FindMultiColorEx(long x1, long y1, long x2, long y2, String^ first_color, String^ offset_color, double sim, long dir) { return ""; }
	//����ָ�������ڵ�ͼƬ
	int OPSoft::FindPic(long x1, long y1, long x2, long y2, String^ files, String^ delta_color, double sim, long dir, long* x, long* y) { return 0; }
	//���Ҷ��ͼƬ
	String^ OPSoft::FindPicEx(long x1, long y1, long x2, long y2, String^ files, String^ delta_color, double sim, long dir) { return ""; }
	//
	//����������Բ��Ҷ��ͼƬ, ���ҷ��������ҵ���ͼ�������.�˺���ͬFindPicEx.ֻ�Ƿ���ֵ��ͬ.(file1,x,y|file2,x,y|...)
	String^ OPSoft::FindPicExS(long x1, long y1, long x2, long y2, String^ files, String^ delta_color, double sim, long dir) { return ""; }
	//����ָ�������ڵ���ɫ��,��ɫ��ʽ"RRGGBB-DRDGDB",ע��,�Ͱ�������ɫ��ʽ�෴
	int OPSoft::FindColorBlock(long x1, long y1, long x2, long y2, String^ color, double sim, long count, long height, long width, long* x, long* y) { return 0; }
	//����ָ�������ڵ�������ɫ��, ��ɫ��ʽ"RRGGBB-DRDGDB", ע��, �Ͱ�������ɫ��ʽ�෴
	String^ OPSoft::FindColorBlockEx(long x1, long y1, long x2, long y2, String^ color, double sim, long count, long height, long width) { return ""; }
	//��ȡ(x,y)����ɫ
	String^ OPSoft::GetColor(long x, long y) { return ""; }
	//
	//����ͼ�����뷽ʽ��Ĭ�ϴ��ڽ�ͼ
	int OPSoft::SetDisplayInput(String^ mode) {
		long ret;
		op.SetDisplayInput(StringToWchar(mode), &ret);
		return ret;
	}

	int OPSoft::LoadPic(String^ file_name)
	{
			long ret;
			op.LoadPic(StringToWchar(file_name), &ret);
			return ret;
	}

	int OPSoft::FreePic(String^ file_name) {
		long ret;
		op.FreePic(StringToWchar(file_name), &ret);
		return ret;
	}
	//���ڴ����Ҫ���ҵ�ͼƬ
	int OPSoft::LoadMemPic(String^ file_name, void* data, long size) { return 0; }
	//
	int OPSoft::GetScreenData(long x1, long y1, long x2, long y2, size_t* data) { return 0; }
	//
	int OPSoft::GetScreenDataBmp(long x1, long y1, long x2, long y2, size_t* data, long* size) { return 0; }
	//
	void OPSoft::GetScreenFrameInfo(long* frame_id, long* time)
	{

	}
	//
	String^ OPSoft::MatchPicName(String^ pic_name) { return ""; }
	//----------------------ocr-------------------------
	//�����ֿ��ļ�
	int OPSoft::SetDict(long idx, String^ file_name) 
	{
		long ret; 
		op.SetDict(idx,StringToWchar(file_name), &ret);
		return ret;
	}
	//�����ڴ��ֿ��ļ�
	int OPSoft::SetMemDict(long idx, String^ data, long size) { 
		long ret;
		op.SetMemDict(idx, StringToWchar(data), size, &ret);
		return ret;
	}
	//ʹ���ĸ��ֿ��ļ�����ʶ��
	int OPSoft::UseDict(long idx) {
		long ret;
		op.UseDict(idx, &ret);
		return ret;
	}
	//ʶ����Ļ��Χ(x1,y1,x2,y2)�ڷ���color_format���ַ���,�������ƶ�Ϊsim,simȡֵ��Χ(0.1-1.0),
	String^ OPSoft::Ocr(long x1, long y1, long x2, long y2, String^ color, double sim) { return ""; }
	//��ʶ�𵽵��ַ������Լ�ÿ���ַ�������.
	String^ OPSoft::OcrEx(long x1, long y1, long x2, long y2, String^ color, double sim) { return ""; }
	//����Ļ��Χ(x1,y1,x2,y2)��,����string(������������ַ��������),�����ط���color_format������λ��
	int OPSoft::FindStr(long x1, long y1, long x2, long y2, String^ strs, String^ color, double simxy) { return 0; }
	//���ط���color_format����������λ��
	String^ OPSoft::FindStrEx(long x1, long y1, long x2, long y2, String^ strs, String^ color, double sim) { 
	
		wstring ret;
		op.FindStrEx(x1,y1,x2,y2,StringToWchar(strs), StringToWchar(color),sim, ret);
		return WStringToString(ret);
	}
	//ʶ����Ļ��Χ(x1,y1,x2,y2)�ڵ��ַ���,�Զ���ֵ����������ָ����ɫ
	String^ OPSoft::OcrAuto(long x1, long y1, long x2, long y2, double sim) { return ""; }
	//���ļ���ʶ��ͼƬ
	String^ OPSoft::OcrFromFile(String^ file_name, String^ color_format, double sim) { return ""; }
	//���ļ���ʶ��ͼƬ,����ָ����ɫ
	String^ OPSoft::OcrAutoFromFile(String^ file_name, double sim) { return ""; }
	//����ƵĻ�е�ֱ��
	String^ OPSoft::FindLine(long x1, long y1, long x2, long y2, String^ color, double sim) { return ""; }

	//��ĳ����д������
	int OPSoft::WriteData(long hwnd, String^ address, String^ data, long size) { return 0; }
	//��ȡ����
	String^ OPSoft::ReadData(long hwnd, String^ address, long size) { return ""; }

}
