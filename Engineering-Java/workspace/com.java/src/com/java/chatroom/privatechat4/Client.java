package com.java.chatroom.privatechat4;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client{ 
	public static void main(String [] args) throws UnknownHostException, IOException{ 
		System.out.println("请输入名称：");
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String id = br.readLine();
		if( id == null || id.equals("") ){
			return ;
		}
		
		Socket client = new Socket("localhost", 9999); 
		
		new Thread(new Send(client, id)).start(); 
		new Thread(new Receive(client)).start(); 
	} 
} 


