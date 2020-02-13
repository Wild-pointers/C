package config;

import com.mchange.v2.c3p0.ComboPooledDataSource;
import org.apache.commons.dbutils.QueryRunner;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.stereotype.Component;

import javax.sql.DataSource;

/**
 * 与连接数据库相关的配置
 */
@Configuration

public class JdbcConfig {
    @Value("${jdbc.driver}")
    private String  driver;

    @Value("${jdbc.url}")
    private String  url;

    @Value("${jdbc.name}")
    private String  name;

    @Value("${jdbc.password}")
    private String  password;

    /**
     * 用于创建一个QuerRunner对象
     * @param dataSource
     * @return
     */
    @Bean(name="runner")
    public QueryRunner createQueryRunner(DataSource dataSource){
        return new QueryRunner(dataSource);
    }

    /**
     * 创建数据源对象
     * @return
     */
    @Bean(name="datasource")
    public DataSource createDataSource(){
        try{
            ComboPooledDataSource ds = new ComboPooledDataSource();
            ds.setDriverClass("driver");
            ds.setJdbcUrl("url");
            ds.setUser("username");
            ds.setPassword("password");
            return ds;
        }catch(Exception e){
            throw new RuntimeException();
        }
    }
}
