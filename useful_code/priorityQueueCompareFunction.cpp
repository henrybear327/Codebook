bool cmp(ii a, ii b)
{
    if(a.first == b.first)
		return a.second > b.second;
    return b.first > a.first;
}

priority_queue< ii, vector<ii>, function<bool(ii, ii)> > pq(cmp);
