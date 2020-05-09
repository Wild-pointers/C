package com.itheima.test;

import com.itheima.dao.IUserDao;
import com.itheima.dao.impl.UserDaoImpl;
import com.itheima.domain.User;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import java.io.InputStream;
import java.util.Date;
import java.util.List;


/**
 * @Author LC
 * @Date 2020/5/5 22:24
 * @Version 1.0
 * 测试mybatis的crud操作
 */
public class MybatisTest {

    private InputStream in;
    private IUserDao userDao;

    @Before//测试方法执行前执行
    public void init() throws Exception{
        //1.读取配置文件，生成字节输入流
        in = Resources.getResourceAsStream("SqlMapConfig.xml");
        //2.获取SqlSessionFactory
        SqlSessionFactory factory = new SqlSessionFactoryBuilder().build(in);
        //3.使用工厂对象创建dao对象
        //4.获取dao的代理对象
        userDao = new UserDaoImpl(factory);
    }

    @After
    public void distory() throws  Exception{
        in.close();
    }

    /**
     * 测试查询所有
     */
    @Test
    public void testFindAll() {

        //5.执行查询所有的方法
        List<User> users = userDao.findAll();
        for(User user : users){
            System.out.println(user);
        }

    }

    /**
     * 测试保存操作
     */
    @Test
    public void testSave() {
        User user = new User();
        user.setUsername("mybatis");
        user.setAddress("宝鸡市金台区");
        user.setSex("男");
        user.setBirthday(new Date());


        //5.执行保存方法
        userDao.saveUser(user);

    }

    /**
     * 测试更新操作
     * @throws Exception
     */
    @Test
    public void testUpdate() {
        User user = new User();
        user.setId(50);
        user.setUsername("mybatis updateUser");
        user.setAddress("宝鸡市金台区");
        user.setSex("男");
        user.setBirthday(new Date());


        //5.执行更新方法
        userDao.updateUser(user);

    }

    /**
     * 测试删除操作
     */
    @Test
    public void deleteUser(){
        //执行删除方法
        userDao.deleteUser(50);
    }

    /**
     * 测试查询操作
     */
    @Test
    public void testFindOne(){
        //执行查询一个方法
        User user = userDao.findById(48);
        System.out.println(user);
    }

    /**
     * 测试模糊查询操作
     */
    @Test
    public void testFindByName(){
        //执行查询一个方法
        List<User> users = userDao.findByName("%王%");
        for (User user: users) {
            System.out.println(user);
        }
    }


}
