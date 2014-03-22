package com.java.chatroom.privatechat4;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List; 

public class MultiServer { 
	private List<MyChannel> all = new ArrayList<MyChannel>(); 
	
	public static void main(String [] args) throws IOException{ 
		new MultiServer().start(); 
	} 
	
	public void start() throws IOException{ 
		ServerSocket serverSocket = new ServerSocket(9999); 
		
		while(true){ 
			System.out.println("等待客户端连接!"); 
			Socket server = serverSocket.accept(); 
			
			MyChannel channel = new MyChannel(server);
			all.add(channel);
			new Thread(channel).start();
		}
	}
	
	/*
	 * 一个客户端一个频道
	 * 1.输入流
	 * 2.输出流
	 * 3.接收
	 * 4.发送
	 */
	private class MyChannel implements Runnable{
		private BufferedReader br;
		private BufferedWriter bw;
		private boolean isRunning = true; 
		private String id; 
		
		public MyChannel(Socket server){
			try {
				br = new BufferedReader(new InputStreamReader(server.getInputStream()));
				bw = new BufferedWriter(new OutputStreamWriter(server.getOutputStream())); 
				
				this.id = br.readLine();
				System.out.println(this.id);
				this.send("欢迎您进入聊天室！");
				this.sendOthers( "欢迎"+this.id+"加入聊天室！", true );
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				isRunning = false;
				CloseUtil.closeAll(br, bw);
				all.remove(this);
			} 
		}
		
		private String receive(){
			String msg = "";
			try {
				msg = br.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				isRunning = false;
				CloseUtil.closeAll(br, bw);
				all.remove(this);
			}
			return msg; 
		}
		
		private void send(String msg){
			if( msg == null || msg.equals("") ){
				return ;
			}
			try {
				bw.write(msg);
				bw.newLine();
				bw.flush();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				isRunning = false;
				CloseUtil.closeAll(br, bw);
				all.remove(this);
			}
		}
		
		private void sendOthers(String msg, boolean isSys){
			if(msg.startsWith("@") && msg.indexOf(':') > -1){
				String name = msg.substring(1, msg.indexOf(':'));
				String content = msg.substring(msg.indexOf(':')+1);
				for( MyChannel i: all ){
					if(i.id.equals(name)){
						i.send(id+"对您悄悄地说："+content);
					}
				}
			}else{
				for( MyChannel i: all ){
					if(i != this){
						if( isSys ){ //系统信息
							i.send("系统信息："+msg);
						}else{
							i.send(this.id+"对所有人说："+msg);
						}
					}
				}
			}
		}
		
		@Override 
		public void run() { 
			// TODO Auto-generated method stub 
			while(isRunning){ 
				//write(read()); 
				sendOthers(this.receive(), false); 
			} 
		} 
	} 
} 


