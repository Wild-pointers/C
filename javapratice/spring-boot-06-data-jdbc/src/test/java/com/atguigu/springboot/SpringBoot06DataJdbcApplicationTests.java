package com.atguigu.springboot;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.SQLException;


@SpringBootTest
class SpringBoot06DataJdbcApplicationTests {

    @Autowired
    DataSource dataSource;

    @Test
    public void test() throws SQLException {
        Connection data = dataSource.getConnection();

        System.out.println("------" + data.getClass());

        System.out.println("------" + dataSource.getClass());

        data.close();
    }

}
