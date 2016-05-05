/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TemplateUtil.h
 * Author: student
 *
 * Created on 5 maja 2016, 18:43
 */

#ifndef TEMPLATEUTIL_H
#define TEMPLATEUTIL_H

template<int ...>
struct seq {
};

template<int N, int ...S>
struct gens : gens<N - 1, N - 1, S...> {
};

template<int ...S>
struct gens < 0, S...> {
    typedef seq<S...> type;
};


#endif /* TEMPLATEUTIL_H */

