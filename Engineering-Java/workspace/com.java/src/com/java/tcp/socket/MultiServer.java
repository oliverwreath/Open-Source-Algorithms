package com.java.tcp.socket;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class MultiServer {
	public static void main(String [] args) throws IOException{
		ServerSocket server = new ServerSocket(8888);
		System.out.println("等待连接!");
		
		while(true){
			Socket socket = server.accept();
			System.out.println("一个客户端建立连接!");
			
			String msg = "欢迎！";
			
			BufferedWriter bw = new BufferedWriter(
					new OutputStreamWriter(
					socket.getOutputStream()));
			
			bw.write(msg); 
			bw.newLine(); 
			bw.flush(); 
		}
	} 
} 
