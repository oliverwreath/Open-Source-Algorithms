package com.java.chatroom.basic;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.net.UnknownHostException;

public class Client {
	public static void main(String [] args) throws UnknownHostException, IOException{
		Socket client = new Socket("localhost", 8888);
		
		BufferedReader br = new BufferedReader(new InputStreamReader(client.getInputStream()));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(client.getOutputStream()));
		
		while(true){
			String echo = br.readLine();
			System.out.println(echo);
		}
	}
	
}