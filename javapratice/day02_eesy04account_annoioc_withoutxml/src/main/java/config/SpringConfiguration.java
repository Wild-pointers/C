package config;

import com.mchange.v2.c3p0.ComboPooledDataSource;
import org.apache.commons.dbutils.QueryRunner;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.*;
import org.springframework.stereotype.Component;

import javax.sql.DataSource;

/**
 *
 * 该类是一个配置类，其作用和xml是一样的
 * spring中的新注解
 * configuration
 *      作用：指定当前类是一个配置类
 * ComponenScan
 *      作用：用于通过注解指定spring在创建容器时要扫描的包
 *      细节：当配置类作为AnnotaionConfigApplicationContext对象创建的参数时，该注解可以不用写。
 *      属性：
 *          value：他和basePackages的作用是一样的，都是用于指定创建容器时要扫描的包
 *              我们使用此注解就等于在xml中配置了：
 *               <context:component-scan base-package="com.itheima"></context:component-scan>
 * Bean
 *      作用：用于把当前方法的返回值作为bean对象存入spring的ioc容器中
 *      属性：name 用于指定bean 的id，默认值为当前方法的名称
 *      细节：当我们用注解配置方法时，如果方法有参数，spring框架会去容器中查找有没有可用的bean对象
 *          查找的方式和Autowired是一样的
 * Import
 *      作用：用于导入其他的配置类
 *      属性：value：用于指定其他配置类的字节码
 *          当我们使用import注解后，有import注解的类就称为父配置类，而导入的就成为子配置类
 * PropertySource
 *      作用：用于指定properties文件的位置
 *      属性:
 *          value:指定文件的名称和路径
 *              关键字：classpath，表示类路径下
 */
@Configuration
@Import(JdbcConfig.class)
@ComponentScan(basePackages = "com.itheima")
@PropertySource("classpath:JdbcConfig.properties")
public class SpringConfiguration {


}
