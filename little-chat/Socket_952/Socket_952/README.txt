支援平台
	本程式只能在 Linux 或是	FreeBSD 上執行
	請先將檔案解開後上傳到以上平台的機器，例如 moon 工作站

相關檔案
	lib.cpp		有關 socket 連線程式的物件
	lib.h		socket 連線程式的物件宣告標頭
	client.cpp	client 端的連線範例，相關的函式說明放在此檔案的最前方
	client.h	client 端的自定資料型態寫在此
	server.cpp	server 端的連線範例，相關的函式說明放在此檔案的最前方
	server.h	server 端的自定資料型態寫在此
	Makefile	編譯文本

	請先將檔案上傳到 Linux 或是 FreeBSD 上，
	再使用 joe 或是 vi 編輯器來閱讀或修改上面的檔案

編譯方法
	在命令列底下打入 "make clean all" 來編譯程式

執行方法
	請開啟兩個終端機連線，一個終端機先打入 "./server" 啟動 server，
	然後再切換到另一個終端機打入 "./client" 啟動 client

相關文件
	檔案操作說明請參考 fopen fclose fread fwrite fseek 這些函式
	查詢方式請在命令列底下打入 "man 函式名稱"
