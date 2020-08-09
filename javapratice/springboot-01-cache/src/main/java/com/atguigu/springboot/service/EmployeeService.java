package com.atguigu.springboot.service;

import com.atguigu.springboot.bean.Employee;
import com.atguigu.springboot.mapper.EmployeeMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cache.annotation.*;
import org.springframework.stereotype.Service;

/**
 * @Author LC
 * @Date 2020/8/6 19:00
 * @Version 1.0
 */

@CacheConfig(cacheNames = "emp") //抽取缓存的公共配置
@Service
public class EmployeeService {


    @Autowired
    EmployeeMapper employeeMapper;

    /**
     * 将方法的运行结果进行缓存：以后再要相同的数据，直接在缓存中获取不用再调用方法
     *
     * cachemanger管理多个cache组件的，对缓存的真正crud操作在cache组件中，每一个缓存组件有自己唯一的名字
     * 几个属性
     *  cacheNames/value：指定缓存的名字，将方法的返回结果放到哪个缓存中，是数组的方式，可以指定多个缓存
     *  key：缓存数据时的key，可以用它指定，默认是使用方法参数的值
     *      编写SpEl表达式：#id：参数id的值 #a0 #p0 #root.args[0]
     *  keyGenerator:key的生成器：可以自己指定key的生成器的组件id
     *      key和keyGenerator二选一
     *  cacheManger：指定缓存管理器：或者指定缓存解析器
     *  condition：指定符合条件的情况下缓存
     *  unless:当unless指定的条件为true，方法的返回值不会缓存；可以获取到结果进行判断
     *      unless = “#result == null” 当结果的返回值为null就不缓存
     *  sync：是否使用异步模式
     *
     *  原理：
     *      1.自动配置类：cacheautoconfiguratio
     *      2.导入缓存的配置类
     *      3.哪个配置类默认生效：simplecacheconfiguration
     *      4.给容器中注册了一个cachemanger
     *      5.可以获取和创建Concurrentmapcache类型的缓存组件：他的作用是将数据保存在concurrentmap中
     *
     *      运行流程;
     * @Cacheable：执行之前先去检查缓存有没有这个数据，默认按照参数的值作为key去查询缓存
     * 如果没有就运行方法并将结果放入缓存,以后再来调用就可以直接使用缓存的数据
     *
     *      1.方法运行之前，先去查询Cahce（缓存组件），按照cacheNames指定的名字去获取
     *          cachemanger先去获取相应的缓存，第一次获取缓存如果没有，会自动创建出来
     *      2.去cache中查找缓存的内容，使用一个key，默认是方法的参数
     *          key是按照某种策略生成的：默认是使用keyGenerator生成的，默认使用simplekeygenerator生成的
     *          simplekeygenerator生成策略，
     *              没有参数：key=new SimpleKey();
     *              一个参数：key=参数的值
     *              多个参数：key=new SimpleKey(params)
     *      3.如果没有查到缓存就调用目标方法，
     *      4.将目标方法的缓存放到缓存中
     *    核心
     *      使用cachemanger按照名字获取cache组件
     *      key使用keygenerator生成的
     *
     *整合redis作为缓存
     * 1.安装redis
     *
     *
     * @param id
     * @return
     *
     */
    @Cacheable(cacheNames = "emp",key = "#id",condition = "#id>0")
    public Employee getEmp(Integer id){
        System.out.println("查询"+id+"号员工");
        Employee emp = employeeMapper.getEmpById(id);
        return emp;
    }

    /**
     * @CachePut：既调用方法又更新缓存数据
     * 修改了数据库的某个数据，同时更新缓存
     * 运行时机，先调用目标方法，将目标方法的结果缓存起来
     *
     * 测试步骤：
     *  1.查询一号员工
     *  2.以后查询还是之前的结果
     *  3.更新1号员工
     *  4.查询1号员工
     *      应该是更新后的员工
     *      为什么是更新前的员工，因为1号员工的key生成策略不同
     */
    @CachePut(value = "emp",key = "#employee.id")
    public Employee update(Employee employee){
        employeeMapper.updateEmp(employee);
        return employee;
    }


    /**
     * @CacheEvirt
     * key:指定要清楚的数据
     * allEntries = true 指定清除这个缓存中的所有数据
     * beforeInvocation = false缓存的清除是否在方法执行之前执行
     *  默认代表是在方法执行之后执行，如果方法出错，缓存就不会被删除
     *
     *
     */
    @CacheEvict(value = "emp",key = "#id")
    public void deleteEmp(Integer id){
        System.out.println("deleteEmp"+id);
//        employeeMapper.deleteEmpById(id);
    }

    //@Cacheing定义复杂的缓存规则
    @Caching(
            cacheable = {
                    @Cacheable(value = "emp",key = "#lastName")
            },
            put = {
                    @CachePut(value = "emp",key = "#result.id"),
                    @CachePut(value = "emp",key = "#result.email")
            }
    )
    public Employee getEmpByLastName(String lastName){
        Employee empByLastName = employeeMapper.getEmpByLastName(lastName);
        return empByLastName;
    }


}
