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
	int OPSoft::CapturePre(String^ file_name) {
		long ret;
		op.CapturePre(StringToWchar(file_name), &ret);
		return ret;
	}

	int OPSoft::SetScreenDataMode(long mode) {
		long ret;
		op.SetScreenDataMode(mode, &ret);
		return ret;
	}

	//---------------------algorithm-------------------------------
	//A���㷨
	String^ OPSoft::AStarFindPath(long mapWidth, long mapHeight, String^ disable_points, long beginX, long beginY, long endX, long endY) {
		wstring ret;
		op.AStarFindPath(mapWidth, mapHeight, StringToWchar(disable_points), beginX, beginY, endX, endY, ret);
		return WStringToString(ret);
	}

	String^ OPSoft::FindNearestPos(String^ all_pos, long type, long x, long y) {
		wstring ret;
		op.FindNearestPos(StringToWchar(all_pos), type, x, y, ret);
		return WStringToString(ret);
	}

	//--------------------windows api------------------------------
	//����ָ������,ö��ϵͳ�з��������Ĵ���
	String^ OPSoft::EnumWindow(long parent, String^ title, String^ class_name, long filter) {
		wstring ret;
		op.EnumWindow(parent, StringToWchar(title), StringToWchar(class_name), filter, ret);
		return WStringToString(ret);
	}
	//����ָ�������Լ���������,ö��ϵͳ�з��������Ĵ���
	String^ OPSoft::EnumWindowByProcess(String^ process_name, String^ title, String^ class_name, long filter) {
		wstring ret;
		op.EnumWindowByProcess(StringToWchar(process_name), StringToWchar(title), StringToWchar(class_name), filter, ret);
		return WStringToString(ret);
	}

	//����ָ��������,ö��ϵͳ�з��������Ľ���PID
	String^ OPSoft::EnumProcess(String^ name) {
		wstring ret;
		op.EnumProcess(StringToWchar(name), ret);
		return WStringToString(ret);
	}
	//�Ѵ�������ת��Ϊ��Ļ����
	System::Tuple<long, long, int>^ OPSoft::ClientToScreen(long ClientToScreen) {
		long ret;
		long x;
		long y;
		op.ClientToScreen(ClientToScreen, &x, &y, &ret);
		return gcnew System::Tuple<long, long, int>(x, y, ret);
	}
	//���ҷ����������߱������Ķ���ɼ�����
	int OPSoft::FindWindow(String^ class_name, String^ title)
	{
		long ret;
		op.FindWindow(StringToWchar(class_name), StringToWchar(title), &ret);
		return ret;
	}
	//����ָ���Ľ������֣������ҿɼ�����
	int OPSoft::FindWindowByProcess(String^ process_name, String^ class_name, String^ title) {
		long ret;
		op.FindWindowByProcess(StringToWchar(process_name), StringToWchar(class_name), StringToWchar(title), &ret);
		return ret;
	}

	//����ָ���Ľ���Id�������ҿɼ�����
	int OPSoft::FindWindowByProcessId(long process_id, String^ class_name, String^ title) {
		long ret;
		op.FindWindowByProcessId(process_id, StringToWchar(class_name), StringToWchar(title), &ret);
		return ret;
	}
	//���ҷ����������߱������Ķ���ɼ�����,���ָ����parent,����parent�ĵ�һ���Ӵ����в���
	int OPSoft::FindWindowEx(long parent, String^ class_name, String^ title)
	{
		long ret;
		op.FindWindowEx(parent, StringToWchar(class_name), StringToWchar(title), &ret);
		return ret;
	}
	//��ȡ���ڿͻ���������Ļ�ϵ�λ��
	System::Tuple<long, long, long, long, int>^ OPSoft::GetClientRect(long hwnd) {
		long ret;
		long x1;
		long y1;
		long x2;
		long y2;
		op.GetClientRect(hwnd, &x1, &y1, &x2, &y2, &ret);
		return gcnew System::Tuple<long, long, long, long, int>(x1, y1, x2, y2, ret);
	}
	//��ȡ���ڿͻ�����Ŀ�Ⱥ͸߶�
	System::Tuple<long, long, int>^ OPSoft::GetClientSize(long hwnd) {
		long ret;
		long w;
		long h;
		op.GetClientSize(hwnd, &w, &h, &ret);
		return gcnew System::Tuple<long, long, int>(w, h, ret);
	}
	//��ȡ���������о������뽹��Ĵ��ھ��
	int OPSoft::GetForegroundFocus() {
		long ret;
		op.GetForegroundFocus(&ret);
		return ret;
	}
	//��ȡ��������,���Ի�ȡ�������Դ�����޷���ȡ���ľ��
	int OPSoft::GetForegroundWindow() {
		long ret;
		op.GetForegroundWindow(&ret);
		return ret;
	}
	//��ȡ���ָ��Ŀɼ����ھ��
	int OPSoft::GetMousePointWindow() {
		long ret;
		op.GetMousePointWindow(&ret);
		return ret;
	}
	//��ȡ��������Ŀɼ����ھ��
	int OPSoft::GetPointWindow(long x, long y) {
		long ret;
		op.GetPointWindow(x, y, &ret);
		return ret;
	}
	//����ָ����pid��ȡ������ϸ��Ϣ
	String^ OPSoft::GetProcessInfo(long pid) {
		wstring ret;
		op.GetProcessInfo(pid, ret);
		return WStringToString(ret);
	}
	//��ȡ���ⴰ��
	int OPSoft::GetSpecialWindow(long flag) {
		long ret;
		op.GetSpecialWindow(flag, &ret);
		return ret;
	}
	//��ȡ����������صĴ��ھ��
	int OPSoft::GetWindow(long hwnd, long flag) {
		long ret;
		op.GetWindow(hwnd, flag, &ret);
		return ret;
	}
	//��ȡ���ڵ�����
	String^ OPSoft::GetWindowClass(long hwnd) {
		wstring ret;
		op.GetWindowClass(hwnd, ret);
		return WStringToString(ret);
	}
	//��ȡָ���������ڵĽ���ID
	int OPSoft::GetWindowProcessId(long hwnd) {
		long ret;
		op.GetWindowProcessId(hwnd, &ret);
		return ret;
	}
	//��ȡָ���������ڵĽ��̵�exe�ļ�ȫ·��
	String^ OPSoft::GetWindowProcessPath(long hwnd) {
		wstring ret;
		op.GetWindowProcessPath(hwnd, ret);
		return WStringToString(ret);
	}
	//��ȡ��������Ļ�ϵ�λ��
	System::Tuple<long, long, long, long, int>^ OPSoft::GetWindowRect(long hwnd) {
		long ret;
		long x1;
		long y1;
		long x2;
		long y2;
		op.GetWindowRect(hwnd, &x1, &y1, &x2, &y2, &ret);
		return gcnew System::Tuple<long, long, long, long, int>(x1, y1, x2, y2, ret);
	}
	//��ȡָ�����ڵ�һЩ����
	int OPSoft::GetWindowState(long hwnd, long flag) {
		long ret;
		op.GetWindowState(hwnd, flag, &ret);
		return ret;
	}
	//��ȡ���ڵı���
	String^ OPSoft::GetWindowTitle(long hwnd) {
		wstring ret;
		op.GetWindowTitle(hwnd, ret);
		return WStringToString(ret);
	}
	//�ƶ�ָ�����ڵ�ָ��λ��
	int OPSoft::MoveWindow(long hwnd, long x, long y) {
		long ret;
		op.MoveWindow(hwnd, x, y, &ret);
		return ret;
	}
	//����Ļ����ת��Ϊ��������
	System::Tuple<long, long, int>^ OPSoft::ScreenToClient(long hwnd) {

		long ret;
		long x;
		long y;
		op.ScreenToClient(hwnd, &x, &y, &ret);
		return gcnew System::Tuple<long, long, int>(x, y, ret);
	}

	//��ָ�����ڷ���ճ������
	int OPSoft::SendPaste(long hwnd) {
		long ret;
		op.SendPaste(hwnd, &ret);
		return ret;
	}
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
	int OPSoft::SetWindowTransparent(long hwnd, long trans) {
		long ret;
		op.SetWindowTransparent(hwnd, trans, &ret);
		return ret;
	}
	//��ָ�����ڷ����ı�����
	int OPSoft::SendString(long hwnd, String^ str) {
		long ret;
		op.SendString(hwnd, StringToWchar(str), &ret);
		return ret;
	}
	//��ָ�����ڷ����ı�����-���뷨
	int OPSoft::SendStringIme(long hwnd, String^ str) {
		long ret;
		op.SendStringIme(hwnd, StringToWchar(str), &ret);
		return ret;
	}
	//���п�ִ���ļ�,��ָ��ģʽ
	int OPSoft::RunApp(String^ cmdline, long mode) {
		long ret;
		op.RunApp(StringToWchar(cmdline), mode, &ret);
		return ret;
	}
	//���п�ִ���ļ�����ָ����ʾģʽ
	int OPSoft::WinExec(String^ cmdline, long cmdshow) {
		long ret;
		op.WinExec(StringToWchar(cmdline), cmdshow, &ret);
		return ret;
	}

	//���������в����ؽ��
	String^ OPSoft::GetCmdStr(String^ cmd, long millseconds) {
		wstring ret;
		op.GetCmdStr(StringToWchar(cmd), millseconds, ret);
		return WStringToString(ret);
	}

	//--------------------Background -----------------------
	//bind window and beign capture screen
	int OPSoft::BindWindow(long hwnd, String^ display, String^ mouse, String^ keypad, long mode)
	{
		long ret;
		op.BindWindow(hwnd, StringToWchar(display), StringToWchar(mouse), StringToWchar(keypad), mode, &ret);
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
	int OPSoft::Capture(long x1, long y1, long x2, long y2, String^ file_name) {
		long ret;
		op.Capture(x1, y1, x2, y2, StringToWchar(file_name), &ret);
		return ret;
	}

	//�Ƚ�ָ�������(x,y)����ɫ
	int OPSoft::CmpColor(long x, long y, String^ color, double sim) {
		long ret;
		op.CmpColor(x, y, StringToWchar(color), sim, &ret);
		return ret;
	}

	//����ָ�������ڵ���ɫ
	Tuple<long, long, int>^ OPSoft::FindColor(long x1, long y1, long x2, long y2, String^ color, double sim, long dir) {
		long ret;
		long x;
		long y;
		op.FindColor(x1, y1, x2, y2, StringToWchar(color), sim, dir, &x, &y, &ret);
		return gcnew Tuple<long, long, int>(x, y, ret);

	}
	//����ָ�������ڵ�������ɫ
	String^ OPSoft::FindColorEx(long x1, long y1, long x2, long y2, String^ color, double sim, long dir) {
		wstring ret;
		op.FindColorEx(x1, y1, x2, y2, StringToWchar(color), sim, dir, ret);
		return WStringToString(ret);
	}
	//����ָ���Ķ�������ɫ����
	Tuple<long, long, int>^ OPSoft::FindMultiColor(long x1, long y1, long x2, long y2, String^ first_color, String^ offset_color, double sim, long dir) {
		long ret;
		long x;
		long y;
		op.FindMultiColor(x1, y1, x2, y2, StringToWchar(first_color), StringToWchar(offset_color), sim, dir, &x, &y, &ret);
		return gcnew Tuple<long, long, int>(x, y, ret);
	}
	//����ָ���Ķ�����������ɫ����
	String^ OPSoft::FindMultiColorEx(long x1, long y1, long x2, long y2, String^ first_color, String^ offset_color, double sim, long dir) {
		wstring ret;
		op.FindMultiColorEx(x1, y1, x2, y2, StringToWchar(first_color), StringToWchar(offset_color), sim, dir, ret);
		return WStringToString(ret);
	}
	//����ָ�������ڵ�ͼƬ
	Tuple<long, long, int>^ OPSoft::FindPic(long x1, long y1, long x2, long y2, String^ files, String^ delta_color, double sim, long dir) {
		long ret;
		long x;
		long y;
		op.FindPic(x1, y1, x2, y2, StringToWchar(files), StringToWchar(delta_color), sim, dir, &x, &y, &ret);
		return gcnew Tuple<long, long, int>(x, y, ret);
	}
	//���Ҷ��ͼƬ
	String^ OPSoft::FindPicEx(long x1, long y1, long x2, long y2, String^ files, String^ delta_color, double sim, long dir) {
		wstring ret;
		op.FindPicEx(x1, y1, x2, y2, StringToWchar(files), StringToWchar(delta_color), sim, dir, ret);
		return WStringToString(ret);
	}
	//
	//����������Բ��Ҷ��ͼƬ, ���ҷ��������ҵ���ͼ�������.�˺���ͬFindPicEx.ֻ�Ƿ���ֵ��ͬ.(file1,x,y|file2,x,y|...)
	String^ OPSoft::FindPicExS(long x1, long y1, long x2, long y2, String^ files, String^ delta_color, double sim, long dir) {
		wstring ret;
		op.FindPicExS(x1, y1, x2, y2, StringToWchar(files), StringToWchar(delta_color), sim, dir, ret);
		return WStringToString(ret);
	}
	//����ָ�������ڵ���ɫ��,��ɫ��ʽ"RRGGBB-DRDGDB",ע��,�Ͱ�������ɫ��ʽ�෴
	Tuple<long, long, int>^ OPSoft::FindColorBlock(long x1, long y1, long x2, long y2, String^ color, double sim, long count, long height, long width) {
		long ret;
		long x;
		long y;
		op.FindColorBlock(x1, y1, x2, y2, StringToWchar(color), sim, count, height, width, &x, &y, &ret);
		return gcnew Tuple<long, long, int>(x, y, ret);
	}

	//����ָ�������ڵ�������ɫ��, ��ɫ��ʽ"RRGGBB-DRDGDB", ע��, �Ͱ�������ɫ��ʽ�෴
	String^ OPSoft::FindColorBlockEx(long x1, long y1, long x2, long y2, String^ color, double sim, long count, long height, long width) {
		wstring ret;
		op.FindColorBlockEx(x1, y1, x2, y2, StringToWchar(color), sim, count, height, width, ret);
		return WStringToString(ret);
	}

	//��ȡ(x,y)����ɫ
	String^ OPSoft::GetColor(long x, long y) {
		wstring ret;
		op.GetColor(x, y, ret);
		return WStringToString(ret);
	}
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
	int OPSoft::LoadMemPic(String^ file_name, void* data, long size) {
		long ret;
		op.LoadMemPic(StringToWchar(file_name), data, size, &ret);
		return ret;
	}

	//
	int OPSoft::GetScreenData(long x1, long y1, long x2, long y2, size_t* data) {
		long ret;
		op.GetScreenData(x1, y1, x2, y2, data, &ret);
		return ret;
	}

	//
	int OPSoft::GetScreenDataBmp(long x1, long y1, long x2, long y2, size_t* data, long* size) {
		long ret;
		op.GetScreenDataBmp(x1, y1, x2, y2, data, size, &ret);
		return ret;
	}

	Tuple<long, long>^ OPSoft::GetScreenFrameInfo()
	{
		long frame_id;
		long time;
		op.GetScreenFrameInfo(&frame_id, &time);
		return gcnew Tuple<long, long>(frame_id, time);
	}

	//
	String^ OPSoft::MatchPicName(String^ pic_name) {
		wstring ret;
		op.MatchPicName(StringToWchar(pic_name), ret);
		return WStringToString(ret);
	}
	//----------------------ocr-------------------------
	//�����ֿ��ļ�
	int OPSoft::SetDict(long idx, String^ file_name)
	{
		long ret;
		op.SetDict(idx, StringToWchar(file_name), &ret);
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
	String^ OPSoft::Ocr(long x1, long y1, long x2, long y2, String^ color, double sim) {
		wstring ret;
		op.Ocr(x1, y1, x2, y2, StringToWchar(color), sim, ret);
		return WStringToString(ret);
	}

	//��ʶ�𵽵��ַ������Լ�ÿ���ַ�������.
	String^ OPSoft::OcrEx(long x1, long y1, long x2, long y2, String^ color, double sim) {
		wstring ret;
		op.OcrEx(x1, y1, x2, y2, StringToWchar(color), sim, ret);
		return WStringToString(ret);
	}
	//����Ļ��Χ(x1,y1,x2,y2)��,����string(������������ַ��������),�����ط���color_format������λ��
	Tuple<long, long, int>^ OPSoft::FindStr(long x1, long y1, long x2, long y2, String^ strs, String^ color, double simxy) {
		long ret;
		long x;
		long y;
		op.FindStr(x1, y1, x2, y2, StringToWchar(strs), StringToWchar(color), simxy, &x, &y, &ret);
		return gcnew Tuple<long, long, int>(x, y, ret);
	}
	//���ط���color_format����������λ��
	String^ OPSoft::FindStrEx(long x1, long y1, long x2, long y2, String^ strs, String^ color, double sim) {

		wstring ret;
		op.FindStrEx(x1, y1, x2, y2, StringToWchar(strs), StringToWchar(color), sim, ret);
		return WStringToString(ret);
	}
	//ʶ����Ļ��Χ(x1,y1,x2,y2)�ڵ��ַ���,�Զ���ֵ����������ָ����ɫ
	String^ OPSoft::OcrAuto(long x1, long y1, long x2, long y2, double sim) {
		wstring ret;
		op.OcrAuto(x1, y1, x2, y2, sim, ret);
		return WStringToString(ret);
	}
	//���ļ���ʶ��ͼƬ
	String^ OPSoft::OcrFromFile(String^ file_name, String^ color_format, double sim) {
		wstring ret;
		op.OcrFromFile(StringToWchar(file_name), StringToWchar(color_format), sim, ret);
		return WStringToString(ret);
	}
	//���ļ���ʶ��ͼƬ,����ָ����ɫ
	String^ OPSoft::OcrAutoFromFile(String^ file_name, double sim) {
		wstring ret;
		op.OcrAutoFromFile(StringToWchar(file_name), sim, ret);
		return WStringToString(ret);
	}

	//����ƵĻ�е�ֱ��
	String^ OPSoft::FindLine(long x1, long y1, long x2, long y2, String^ color, double sim) {
		wstring ret;
		op.FindLine(x1, y1, x2, y2, StringToWchar(color), sim, ret);
		return WStringToString(ret);
	}

	//��ĳ����д������
	int OPSoft::WriteData(long hwnd, String^ address, String^ data, long size) {
		long ret;
		op.WriteData(hwnd, StringToWchar(address), StringToWchar(data), size, &ret);
		return ret;
	}

	//��ȡ����
	String^ OPSoft::ReadData(long hwnd, String^ address, long size) {
		wstring ret;
		op.ReadData(hwnd, StringToWchar(address), size, ret);
		return WStringToString(ret);
	}

	OPSoft::~OPSoft()
	{

	}

	

	int KMSoft::Open()
	{
		if (km_handle != NULL)return 1;
		
		km_handle = M_Open(1);
		return km_handle == NULL ? 0 : 1;
	}

	int KMSoft::Open_VidPid(int Vid, int Pid)
	{
		if (km_handle != NULL)return 1;
		auto handle = M_Open_VidPid(Vid, Pid);
		return km_handle == NULL ? 0 : 1;
	}

	int KMSoft::Close()
	{
		try 
		{
			//δ֪���󿪰�
			
	/*		 M_Close(km_handle);
			 km_handle = NULL;*/
		}
		catch (...)
		{
			
		}

		return 1;
	}

	int KMSoft::MoveR(int x, int y)
	{
		if (km_handle == NULL)return 0;
		return M_MoveR(km_handle, x, y);

	}

	int KMSoft::MoveTo(int x, int y)
	{
		if (km_handle == NULL)return 0;
		return M_MoveTo(km_handle, x, y);
	}

	KMSoft::~KMSoft()
	{
		if (km_handle != NULL)km_handle = NULL;
	}

}
