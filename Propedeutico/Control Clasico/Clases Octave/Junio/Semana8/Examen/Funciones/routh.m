function [RA,s_out] = routh(poli,epsilon);

%ROUTH   Routh array.
%   RA=ROUTH(R,EPSILON) returns the symbolic Routh array RA for 
%   polynomial R(s). The following special cases are considered:
%   1) zero first elements and 2) rows of zeros. All zero first 
%   elements are replaced with the symbolic variable EPSILON
%   which can be later substituted with positive and negative 
%   small numbers using SUBS(RA,EPSILON,...). When a row of 
%   zeros is found, the auxiliary polynomial is used.
%
%	Examples:
%
%	1) Routh array for s^5+s^4+2*s^3+2*s^2+s+1
%
%		>>syms EPS
%		>>[ra,s]=routh([1 1 2 2 1 1],EPS)
% ra =
%  
%       [ 1, 2, 1]
%       [ 1, 2, 1]
%       [ 4, 4, 0]
%       [ 1, 1, 0]
%       [ 2, 0, 0]
%       [ 1, 0, 0]
% 
% s =
% 
% special case: There were rows of zeros in row(3)
% special case: There were rows of zeros in row(5)
% You can determin the stabilization of the system just according to sign of the first column of the Routh-Hurwitz array.
%
%	2) Routh array for s^3+a*s^2+b*s+c
%	
%		>>syms a b c EPS;
%		>>[ra,s]=routh([1 a b c],EPS);
%		ra =
% 
%		[          1,          b]
%		[          a,          c]
%		[ (-c+b*a)/a,          0]
%		[          c,          0]
%
%      s =
% You can determin the stabilization of the system just according to sign of the first column of the Routh-Hurwitz array.
% 
%   Author:Rivera-Santos, Edmundo J.
%   E-mail:edmundo@alum.mit.edu
%   modified by xianfa110

if(nargin<2),
	fprintf('\nError: Not enough input arguments given.');
	return
end

coeff = length(poli);				%get number of coefficients
RA = sym(zeros(coeff,ceil(coeff/2)));	%initialize symbolic Routh array 
s_out = '';

for i=1:coeff,
	RA(2-rem(i,2),ceil(i/2))=poli(i); %assemble 1st and 2nd rows
end

rows=coeff-2;		%number of rows that need determinants
index=zeros(rows,1);	%initialize columns-per-row index vector

for i=1:rows,
	index(rows-i+1)=ceil(i/2); %form index vector from bottom to top
end

for i=3:coeff,				%go from 3rd row to last
	if(all(RA(i-1,:)==0)),		%row of zeros
            tmp = sprintf('special case: The elements of row(%d) are all zero\n',i-1);
            s_out = [s_out,tmp];
			a=coeff-i+2;		%order of auxiliary equation
			b=ceil(a/2)-rem(a,2)+1; %number of auxiliary coefficients
			temp1=RA(i-2,1:b);	%get auxiliary polynomial
			temp2=a:-2:0;		%auxiliry polynomial powers
			RA(i-1,1:b)=temp1.*temp2;	%derivative of auxiliary
	elseif(RA(i-1,1)==0),		%first element in row is zero
            tmp = sprintf('special case: The first element in row(%d) is 0. Compute with e instead.\n',i-1);
            s_out = [s_out,tmp];
			RA(i-1,1)=epsilon;	%replace by epsilon
	end
				%compute the Routh array elements
	for j=1:index(i-2),	
		RA(i,j)=-det([RA(i-2,1) RA(i-2,j+1);RA(i-1,1) RA(i-1,j+1)])/RA(i-1,1);
    end   
end
s_out = [s_out,'You can determinate the stabilization of the system just according to sign of the first column of the Routh-Hurwitz array.'];
RA = simplify(RA);
end