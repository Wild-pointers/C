package com.itheima.dao.impl;

import com.itheima.dao.IUserDao;
import com.itheima.domain.User;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import java.util.List;

/**
 * @Author LC
 * @Date 2020/5/8 16:01
 * @Version 1.0
 */
public class UserDaoImpl implements IUserDao {

    private SqlSessionFactory factory;

    public UserDaoImpl(SqlSessionFactory factory){
        this.factory = factory;
    }

    @Override
    public List<User> findAll() {
        //1.根据factory获取sqlSession对象
        SqlSession session = factory.openSession();
        //2.调用sqlSession中的方法，实现查询列表
        List<User> users = session.selectList("com.itheima.dao.IUserDao.findAll");//参数就是配置文件中的namespace和key
        //3.释放资源
        session.close();
        return users;
    }

    @Override
    public void saveUser(User user) {
        //1.根据factory获取SqlSession对对象.
        SqlSession session = factory.openSession();
        //2.调用方法实现保存
        session.insert("com.itheima.dao.IUserDao.saveUser",user);
        //3.提交事务
        session.commit();
        //4.释放资源
        session.close();
    }

    @Override
    public void updateUser(User user) {
        //1.根据factory获取SqlSession对对象.
        SqlSession session = factory.openSession();
        //2.调用方法实现更新
        session.insert("com.itheima.dao.IUserDao.updateUser",user);
        //3.提交事务
        session.commit();
        //4.释放资源
        session.close();
    }

    @Override
    public void deleteUser(Integer userId) {
        //1.根据factory获取SqlSession对对象.
        SqlSession session = factory.openSession();
        //2.调用方法实现更新
        session.update("com.itheima.dao.IUserDao.deleteUser",userId);
        //3.提交事务
        session.commit();
        //4.释放资源
        session.close();
    }

    @Override
    public User findById(Integer userId) {
        //1.根据factory获取SqlSession对对象.
        SqlSession session = factory.openSession();
        //2.调用方法实现查找一个
        User user = session.selectOne("com.itheima.dao.IUserDao.findById",userId);
        //3.提交事务
        session.commit();
        //4.释放资源
        session.close();
        return user;
    }

    @Override
    public List<User> findByName(String name) {
        //1.根据factory获取SqlSession对对象.
        SqlSession session = factory.openSession();
        //2.调用方法实现更新
        List<User> users = session.selectList("com.itheima.dao.IUserDao.findByName",name);
        //3.提交事务
        session.commit();
        //4.释放资源
        session.close();
        return users;
    }
}
