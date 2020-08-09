package com.atguigu.springboot.mapper;

import com.atguigu.springboot.bean.Employee;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.springframework.stereotype.Component;

/**
 * @Author LC
 * @Date 2020/8/6 21:31
 * @Version 1.0
 */
@Mapper
@Component
public interface EmployeeMapper {

    @Select("select * from employee where id=#{id}")
    public Employee getEmpById(Integer id);

    @Insert("insert into employee (lastName,email,gender,d_Id)values(#{lastName},#{email},#{gender},#{dId})")
    public Employee insertEmployee(Employee employee);

    public void deleteEmpById();
}
