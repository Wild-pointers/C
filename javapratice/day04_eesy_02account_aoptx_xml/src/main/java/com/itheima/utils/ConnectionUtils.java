package com.itheima.utils;

import javax.sql.DataSource;
import javax.xml.crypto.Data;
import java.sql.Connection;

/**
 * 连接的工具类，用于从数据源获取一个连接，并且实现和线程的绑定
 */
public class ConnectionUtils {

    private ThreadLocal<Connection> tl = new ThreadLocal<Connection>();

    private DataSource dataSource;

    public void setDataSource(DataSource dataSource) {
        this.dataSource = dataSource;
    }

    /**
     * 获取当前线程上的连接
     */
    public Connection getThreadConnection(){
            //1.先从Threadlocal上获取
            Connection conn = tl.get();
        try{
            //2.判断当前线程上是否有链接
            if(conn == null){
                //3.从数据源中获取一个连接，并存入ThreadLocal中
                conn = dataSource.getConnection();
                tl.set(conn);
            }

        }catch (Exception e){
            e.printStackTrace();
        }
        return conn;
    }
    public void removeConnection(){
        tl.remove();
    }
}
